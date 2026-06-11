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

ll n, a[100005][3];
ll dp[100005][3][3];

ll solve(int pos, int konta, int koydin)
{
    if(pos == n) return 0;
    if(dp[pos][konta][koydin]!=-1) return dp[pos][konta][koydin]; 

    ll res = 0;
    if(koydin<1) res = max(res, a[pos][konta] + solve(pos+1, konta, koydin+1));
    if(konta == 0)
    {
        res = max(res, a[pos][1] + solve(pos+1, 1, 1));
        res = max(res, a[pos][2] + solve(pos+1, 2, 1));
    }
    if(konta == 1)
    {
        res = max(res, a[pos][0] + solve(pos+1, 0, 1));
        res = max(res, a[pos][2] + solve(pos+1, 2, 1));
    }
    if(konta == 2)
    {
        res = max(res, a[pos][1] + solve(pos+1, 1, 1));
        res = max(res, a[pos][0] + solve(pos+1, 0, 1));
    }
    return dp[pos][konta][koydin] = res;
}

int main()
{
    cin>>n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
    }
    cout<<solve(0,2,0); nn;
}