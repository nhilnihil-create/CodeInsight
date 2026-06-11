#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e4;
const int bias=1e4;
bool dp[2][MAXN];
char s[10000];
vector<int> h,v;

int main()
{
    while(scanf("%s",s+1)!=EOF)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        memset(dp,false,sizeof(dp));
        int len=strlen(s+1);
        h.clear();v.clear();
        int first=0;
        int p=1;
        while(p<=len&&s[p]=='F') {first++;p++;}
        dp[0][first+bias]=true;
        p++;
        bool horizontal=false;
        int tmp=0;
        for(;p<=len;p++)
        {
            tmp=0;
            while(s[p]=='F'&&p<=len)
            {
                tmp++;
                p++;
            }
            if(horizontal&&tmp) h.push_back(tmp);
            else if(tmp) v.push_back(tmp);
            horizontal=!horizontal;
        }
        int now=0;
        for(auto i:h)
        {
            now^=1;
            for(int j=0;j<=MAXN;j++)
            {
                if(dp[now^1][j])
                {
                    dp[now][j+i]=true;
                    dp[now][j-i]=true;
                }
            }
            for(int j=0;j<=MAXN;j++)
                dp[now^1][j]=false;
        }
        if(!dp[now][bias+x])
        {
            cout<<"No"<<endl;
        }else
        {
            memset(dp,false,sizeof(dp));
            dp[0][0+bias]=true;
            int now=0;
            for(auto i:v)
            {
                now^=1;
                for(int j=0;j<=MAXN;j++)
                {
                    if(dp[now^1][j])
                    {
                        dp[now][j+i]=true;
                        dp[now][j-i]=true;
                    }
                }
                for(int j=0;j<=MAXN;j++)
                    dp[now^1][j]=false;
            }
            if(!dp[now][y+bias])
                cout<<"No"<<endl;
            else cout<<"Yes"<<endl;
        }
    }
    return 0;
}