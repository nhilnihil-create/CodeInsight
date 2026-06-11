#include<bits/stdc++.h>
#include<ext/rope>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define C 0.5772156649
#define pi acos(-1.0)
#define ll long long
#define mod 1000000007
#define ls l,m,rt<<1
#define rs m+1,r,rt<<1|1

using namespace std;
using namespace __gnu_cxx;

const double g=10.0,eps=1e-7;
const int N=200000+10,maxn=1000000+10,inf=0x3f3f3f;

int cnt[1<<26],num[26],dp[N];
char s[N];
int main()
{
    scanf("%s",s+1);
    memset(cnt,-1,sizeof cnt);
    cnt[0]=dp[0]=0;
    int len=strlen(s+1);
    for(int i=1;i<=len;i++)
    {
        dp[i]=i;
        num[s[i]-'a']++;
        int even=0;
        for(int j=0;j<26;j++)
            if(num[j]&1)
                even++;
        if(even<=1)dp[i]=1;
    }
    memset(num,0,sizeof num);
    for(int i=1;i<=len;i++)
    {
        num[s[i]-'a']++;
        int k=0;
        for(int j=0;j<26;j++)
            if(num[j]&1)
                k+=(1<<j);
        if(cnt[k]!=-1)dp[i]=min(dp[i],dp[cnt[k]]+1);
        for(int j=0;j<26;j++)
        {
            if(k==(1<<j))dp[i]=1;
            if(cnt[k^(1<<j)]!=-1)
            {
                dp[i]=min(dp[i],dp[cnt[k^(1<<j)]]+1);
            }
        }
        cnt[k]=i;
    }
  //  for(int i=1;i<=len;i++)cout<<dp[i]<<endl;
    printf("%d\n",dp[len]);
    return 0;
}
/************
k^(1<<i)=s
************/
