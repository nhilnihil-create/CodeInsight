#include <bits/stdc++.h>
#define ll long long 
#define vpnt(ans) for(ll i = 0; i < ans.size(); i++) cout << ans[i] << (i + 1 < ans.size() ? ' ' : '\n');
#define setbit(x,k) (x |= (1 << k))
#define clearbit(x,k) (x &= ~(1ll << k))
#define checkbit(x,k) (x & (1ll << k))
#define mp make_pair
#define scl(x) scanf("%lld",&x)
#define sci(x) scanf("%d",&x)
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define pii pair<int,int> 
#define YES printf("YES\n")
#define Yes printf("Yes\n")
#define yes printf("yes\n")
#define NO printf("NO\n")
#define No printf("No\n")
#define no printf("no\n")
#define nn printf("\n") 
#define mod 10000007
using namespace std;    

ll n,k;
ll h[100005];
ll dp[100005];
ll solve(int pos)
{
    if(pos>=n-1) return 0;
    if(dp[pos]!=-1) return dp[pos];
    ll res = LONG_LONG_MAX;
    for(int i=1; i<=k && pos+i<n; i++) 
    {
        res = min(res, abs(h[pos] - h[pos+i]) + solve(pos+i));
    }
    
    return dp[pos] = res;
    
}

int main() 
{
   memset(dp, -1 , sizeof(dp));
   cin>>n>>k;
   for(int i=0; i<n; i++) cin>>h[i];
   cout<<solve(0); nn;
}