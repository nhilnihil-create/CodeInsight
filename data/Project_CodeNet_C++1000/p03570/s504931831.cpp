#include<iostream>
#include<cmath>
#include<string.h>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
using namespace std;

char s[200011];
int n;
map<int,int>dp;
int main()
{
    int i,j,k;
    
    scanf("%s",s+1);
    n=strlen(s+1);
    
    dp[0]=0;
    int f=0;
    
    int now=0x3f3f3f3f;
    for(i=1;i<=n;i++)
    {
        f^=(1<<(s[i]-'a'));
        now=0x3f3f3f3f;
        if(dp.find(f)!=dp.end())
        {
            now=min(now,dp[f]);
        }
        for(j=0;j<26;j++)
        {
            int tmp=(f^(1<<(j)));
            if(dp.find(tmp)!=dp.end())
            {
                now=min(now,dp[tmp]);
            }
        }
        
        //cout<<f<<' '<<now<<endl;
        
        if(now!=0x3f3f3f3f)
        {
        if(dp.find(f)==dp.end())
        {
            dp[f]=now+1;
        }
        else
        {
            dp[f]=min(dp[f],now+1);
        }
        }
    }
    
    cout<<now+1<<endl;
    
    
    return 0;
}
