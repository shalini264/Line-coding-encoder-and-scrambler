
#include<bits/stdc++.h>
#include<graphics.h>
using namespace std;
string generateRand(int n)
{   vector<int>vec;
    string ans;
    srand((unsigned int) time(0));
    for(int i=1;i<=n;i++)
    {
        vec.push_back(i);
        vec[i]=rand()%2;
        ans.push_back(vec[i]+'0');
    }
    return ans;
}
string lcs(string &x,string &y)
{
    int m=x.size();
    int n=y.size();
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(x[i-1]==y[j-1])
                dp[i][j]=dp[i-1][j-1]+1;
            else
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
    int index=dp[m][n];
    string temp(index+1,'\0');
    int i=m,j=n;
    while(i>0 && j>0)
    {
        if(x[i-1]==y[j-1])
        {
            temp[index-1]=x[i-1];
            i--;
            j--;
            index--;
        }
        else if(dp[i-1][j]>dp[i][j-1])
            i--;
        else
            j--;
    }
    return temp;
}
string longPal(string &str)
{
    string rev=str;
    reverse(rev.begin(),rev.end());
    return lcs(str,rev);
}
void NRZL(string s)
{
    int n=s.size();
    settextstyle(0,0,0);
    int x=20;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {
            line(x,100,x+40,100);
            outtextxy(x+18,25,"0");
        }
        else if(s[i]=='1')
        {
            rectangle(x,50,x+40,100);
            outtextxy(x+16,25,"1");
            setcolor(0);
            line(x,100,x+40,100);
            if(s[i-1]=='1' && i>0)
                {setcolor(0);line(x,50,x,100);}
            setcolor(4);
        }
        x=x+40;
    }
    settextstyle(0,1,2);
    outtextxy(0,150,"amplitude");

}
void NRZI(string s)
{
    int n=s.size();
    settextstyle(0,0,0);
    int x=20,flag=0;
    if(s[0]=='0')
    {
        line(x,100,x+40,100);
        outtextxy(x+18,25,"0");
        flag=0;
    }
    else
    {
        rectangle(x,50,x+40,100);
        outtextxy(x+18,25,"1");
        setcolor(0);
        line(x,100,x+40,100);
        flag=1;
        setcolor(4);
    }
    x=x+40;
    for(int i=1;i<n;i++)
    {  if(s[i]=='0')
        {outtextxy(x+18,25,"0");
        if(flag==0)
        {
            line(x,100,x+40,100);
            flag=0;
        }
        else if(flag==1)
        {
            rectangle(x,50,x+40,100);
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=1;
        }
        x=x+40;
       }
       else if(s[i]=='1')
       {outtextxy(x+18,25,"1");
       if(flag==1)
        {
            line(x,100,x+40,100);
            flag=0;
        }
        else if(flag==0)
        {
            rectangle(x,50,x+40,100);
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=1;
        }
        x=x+40;

       }}
    settextstyle(0,1,2);
    outtextxy(0,150,"amplitude");
}
void MANCHESTER(string s)
{
    int n=s.size();
    int x=20;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {   rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"0");
            setcolor(0);
            line(x,100,x+20,100);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,100,x+40,100);
        }
        else if(s[i]=='1')
        {
            rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"1");
            setcolor(0);
            line(x,200,x+20,200);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,200,x+40,200);
        }
        x=x+40;
    }
    settextstyle(0,1,2);
    outtextxy(0,150,"amplitude");

}
void DIFMAN(string s)
{
    int n=s.size();

    int x=20,flag=0;
    if(s[0]=='0')
        {   rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"0");
            setcolor(0);
            line(x,100,x+20,100);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,100,x+40,100);
            flag=0;
        }
        else if(s[0]=='1')
        {
            rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"1");
            setcolor(0);
            line(x,200,x+20,200);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,200,x+40,200);
            flag=1;
        }
        x=x+40;
    for(int i=1;i<n;i++)
    {  if(s[i]=='0')
        {if(flag==0)
        {   rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"0");
            setcolor(0);
            line(x,100,x+20,100);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,100,x+40,100);
        }
        else if(flag==1)
        {
            rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"1");
            setcolor(0);
            line(x,200,x+20,200);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,200,x+40,200);
        }
        x=x+40;
    }
    else if(s[i]=='1')
    {
        if(flag==1)
        {   rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"1");
            setcolor(0);
            line(x,100,x+20,100);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,100,x+40,100);
            flag=0;
        }
        else if(flag==0)
        {
            rectangle(x,100,x+20,200);
            outtextxy(x+18,25,"1");
            setcolor(0);
            line(x,200,x+20,200);
            line(x,100,x,200);
            setcolor(4);
            line(x+20,200,x+40,200);
            flag=1;
        }
        x=x+40;
    }}
    settextstyle(0,1,2);
    outtextxy(0,200,"amplitude");
}
void AMI(string s)
{
    int n=s.size();
    int x=20,flag=0;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0')
        {line(x,100,x+40,100);
        outtextxy(x+18,30,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             rectangle(x,50,x+40,100);
             outtextxy(x+18,30,"1");
             setcolor(0);
             line(x,100,x+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(x,100,x+40,150);
            outtextxy(x+18,30,"1");
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=0;
            }
        }
        x=x+40;
    }
    settextstyle(1,1,1);
    outtextxy(0,150,"amplitude");
}
void B8ZS(string s,int &flag1,int &x)
{
    int flag;
    int n=s.size();
    for(int i=0;i<n;i++)
    {   if(i==3||i==7)
         {
             if(flag1==0)
                flag=1;
             else
                flag=0;
         }
         if(i==4||i==6)
         {  flag=flag1;
         }
        if(s[i]=='0'&& i!=4 && i!=3 && i!=6 && i!=7)
        {line(x,100,x+40,100);
        outtextxy(x+18,30,"0");
        }
        else
        {
            if(flag==0)
            {
             rectangle(x,50,x+40,100);
             outtextxy(x+18,30,"0");
             setcolor(0);
             line(x,100,x+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(x,100,x+40,150);
            outtextxy(x+18,30,"0");
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=0;
            }
        }
        x=x+40;
    }
    flag1=flag;
    settextstyle(1,1,1);
    outtextxy(0,150,"amplitude");
        }
void AMIB8ZS(string s)
{
    int n=s.size();
    if(n==8)
    {  int x=20,flag=0;
        if(s=="00000000")
        {
          B8ZS(s,flag,x);
        }
        else
            AMI(s);
    }
    else if(n<8)
        AMI(s);
    else
    {
        int x=20,flag=0;
    for(int i=0;i<n;i++)
    { if(s[i]=='0')
        {
            string substring=s.substr(i,8);
            if(substring=="00000000")
            {B8ZS(substring,flag,x);
             i=i+7;
             continue;}


        }
        settextstyle(1,0,1);
        if(s[i]=='0')
        {line(x,100,x+40,100);
        outtextxy(x+18,30,"0");
        }
        else if(s[i]=='1')
        {
            if(flag==0)
            {
             rectangle(x,50,x+40,100);
             outtextxy(x+18,30,"1");
             setcolor(0);
             line(x,100,x+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(x,100,x+40,150);
            outtextxy(x+18,30,"1");
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=0;
            }
        }
        x=x+40;
    }
    settextstyle(1,1,1);
    outtextxy(0,150,"amplitude");
    }
}
void HDB3(string s,int &flag1,int &x,int sum)
{
    int flag,n;
    n=s.size();
    for(int i=0;i<n;i++)
    {   if(sum%2==0)
        {if(i==0||i==3)
         {
             flag=flag1;
         }}
         else
         {if(i==3)
           {if(flag1==0)
             flag=1;
             else
                flag=0;
         }}
        if(s[i]=='0'&& i!=3 && i!=0 ||(i==0 && (sum%2!=0 )))
        {line(x,100,x+40,100);
        outtextxy(x+18,30,"0");
        }
        else
        {
            if(flag==0)
            {
             rectangle(x,50,x+40,100);
             outtextxy(x+18,30,"0");
             setcolor(0);
             line(x,100,x+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(x,100,x+40,150);
            outtextxy(x+18,30,"0");
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=0;
            }
        }
        x=x+40;
    }
    flag1=flag;
    settextstyle(1,1,1);
    outtextxy(0,150,"amplitude");

}
void AMIHDB3(string s)
{
    int n=s.size();
        int x=20,flag=0,sum=0;
    for(int i=0;i<n;i++)
    {    if(s[i]=='0')
        {
            string sub=s.substr(i,4);
            if(sub=="0000")
                {HDB3(sub,flag,x,sum);
                 i=i+3;
                 continue;
                }
        }
        settextstyle(1,0,1);
        if(s[i]=='0')
        {line(x,100,x+40,100);
        outtextxy(x+18,30,"0");
        }
        else if(s[i]=='1')
        {   sum++;
            if(flag==0)
            {
             rectangle(x,50,x+40,100);
             outtextxy(x+18,30,"1");
             setcolor(0);
             line(x,100,x+40,100);
             setcolor(4);
             flag=1;
            }
            else
            {rectangle(x,100,x+40,150);
            outtextxy(x+18,30,"1");
            setcolor(0);
            line(x,100,x+40,100);
            setcolor(4);
            flag=0;
            }
        }
        x=x+40;
    }
    settextstyle(1,1,1);
    outtextxy(0,150,"amplitude");
}
int main()
{
    int gd=DETECT,gm,choice,scramb;
    char ch;
    initgraph(&gd,&gm,(char*)"");
    setcolor(4);
    setfillstyle(2,5);
    settextstyle(1,0,1);
    string s,s1;
    s=generateRand(15);
    s1=longPal(s);
    cout<<s<<" "<<s1<<"\n";
    cout<<"Enter Line encoding scheme-\n1)NRZ-L\n2)NRZ-I\n3)MANCHESTER\n4)DIFFERENTIAL MANCHESTER\n5)AMI";
    cin>>choice;
    if(choice==1)
    {
        NRZL(s1);
    }
    else if(choice==2)
    {
        NRZI(s1);
    }
    else if(choice==3)
    {
        MANCHESTER(s1);
    }
    else if(choice==4)
    {
        DIFMAN(s1);
    }
    else if(choice==5)
    {
        cout<<"Require Scrambling (Y/N)?";
        cin>>ch;
        if(ch=='Y')
        {
            cout<<"Type of scrambling:\n1)B8ZS\n2)HDB3";
            cin>>scramb;
            if(scramb==1)
               AMIB8ZS(s1);
            else
            {
              AMIHDB3(s1);
            }
               
        }
        else
        {
          AMI(s1);
        }
    }

    getch();
    closegraph();
}
