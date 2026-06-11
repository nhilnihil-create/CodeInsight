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

bool compare(vector<ll> &A, vector<ll> &B) {
    if(A[0]+A[1]<B[0]+B[1])
        return 1;
    return 0;
}

int main() {

    get(n);

    vector<vector<ll>> A;
    rep(i,n) {
        get3(a,b,c);
        A.pb(vector<ll> {a,b,c});

    }

    sort(ALL(A), compare);

    vector<vector<ll>> dp(n+1, vector<ll>(50001,0));

    ll maxi = 0;
    rep(i,n) {
        rep(j,50001) {
            dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
            if(j+A[i][0]>50001)
                continue;
            if(j<=A[i][1] || i==0) {
                dp[i+1][j+A[i][0]] = max(dp[i+1][j+A[i][0]], dp[i][j]+A[i][2]);
                // cout<<i+1<< " " <<j<<" "<<dp[i+1][j+A[i][1]] <<endl;
                maxi = max(maxi, dp[i+1][j+A[i][0]]);
            }   
        }
    }
    
    // for(auto i:A)
    //     cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;

    

    // rep(i,n+1) {
    // rep(j,n+1)
    // cout<<dp[i][j]<<" ";
    // cout<<endl;
    // }
    printf("%lld\n", maxi);

    return 0;  
}