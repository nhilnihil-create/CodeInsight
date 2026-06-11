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
#define mod 1000000007
using namespace std;

string s[10000];
ll h,w;
ll dp[1005][1005];

ll solve(int r, int c)
{
    if(r==h-1 && c == w-1) return 1;
    if(dp[r][c]!=-1) return dp[r][c];

    ll res = 0;
    if(r+1<h && s[r+1][c]!='#') res += solve(r+1, c);
    if(c+1<w && s[r][c+1]!='#') res += solve(r, c+1);
    return dp[r][c] = res%mod;
}

int main()
{
    memset(dp, -1, sizeof(dp));
    cin>>h>>w;
    for(int i=0; i<h; i++) cin>>s[i];
    cout<<solve(0,0); nn;

}