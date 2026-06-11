#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int ll;
vector<ll>tree[100001];
ll n;
ll dp[100001][2];
ll const mod = 1e9+7;
void dfs(ll,ll);
int main()
{
    scanf("%lld",&n);
    memset(dp,-1,sizeof(dp));
    for(int i = 0 ; i < n-1; i++)
    {
        ll a, b;
        scanf("%lld%lld",&a,&b);
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    //start dp
    dfs(1,1);
    printf("%lld\n",(dp[1][0]+dp[1][1])%mod);
}
void dfs(ll e,ll p)
{
    //calculate value
    if(dp[e][0]!=-1&&dp[e][1]!=-1)return;
    //calculate two sums
    dp[e][0] = dp[e][1] = 1;
    for(int i = 0 ; i < tree[e].size(); i++)
    {
        if(tree[e][i]==p)continue;
        dfs(tree[e][i],e);
        dp[e][0] = (dp[e][0]*dp[tree[e][i]][1])%mod;
        dp[e][1] = (dp[e][1]*((dp[tree[e][i]][1]+dp[tree[e][i]][0])%mod))%mod;
    }
    return;

}
