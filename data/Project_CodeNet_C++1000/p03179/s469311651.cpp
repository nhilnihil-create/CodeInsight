// #pragma GCC optimize("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define N 1000000007
#define N2 998244353
#define Nmax 100001
#define INF (ll)1e18
#define pll pair<ll,ll>
#define pii pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(ll i=m;i<(n);i++)
#define repr(i,n) repr2(i,n,0)
#define repr2(i,m,n) for(ll i=m;i>=(n);i--)
#define get(n) ll (n); scanf("%lld",&(n));
#define get2(n,k) ll (n),(k); scanf("%lld%lld",&(n),&(k));
#define get3(n,m,k) ll (n),(m),(k); scanf("%lld%lld%lld",&(n),&(m),&(k));
#define gets(s) string (s); cin >> (s);
#define ALL(c) (c).begin(),(c).end()
#define fill_nums(A,n) vector<ll> A((n)); for(ll i=0;i<n;i++) scanf("%lld",&A[i]);
#define fill_edges(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1); adj[b-1].pb(a-1);}
#define fill_direct(adj,m) for(ll i=0;i<m;i++) {ll a, b; scanf("%lld %lld",&a,&b); adj[a-1].pb(b-1);}
#define pi 3.1415926535897

int main() {

    get(n);
    gets(s);

    s.insert(0,1,'<');

    vector<vector<ll>> dp(n+1, vector<ll>(n+1,0));
    dp[n][0]=1;

    repr(i,n-1) {
        ll nums = n-i;
        rep(j,nums+1) {
            if(s[i]=='<')
                dp[i][j] = ((dp[i][j] + (j-1>=0 ? dp[i+1][j-1] : 0))%N+N)%N;
            else
                dp[i][j] = ((dp[i][j] + (nums-1>=0 ? dp[i+1][nums-1] : 0) - (j-1>=0 ? dp[i+1][j-1] : 0))%N+N)%N;
        }

        rep2(j,1,n+1) {
            dp[i][j] = (dp[i][j] + dp[i][j-1])%N;
        }
    }

    printf("%lld\n", (N+dp[0][n]-dp[0][n-1])%N);

    return 0;  
}