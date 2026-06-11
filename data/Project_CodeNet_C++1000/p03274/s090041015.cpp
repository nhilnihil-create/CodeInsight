#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define rep(i, n) for(int i=0;i<(int)n;i++)
#define PI acos(-1)
#define fast_io ios_base::sync_with_stdio(false) ; cin.tie(0); cout.tie(0);
ll mod=1e9+7;

ll dp[200200];
int main(){
    fast_io

    int n, k;
    cin>>n>>k;
    vector<ll> x(n);
    rep(i,n) cin>>x[i];
    ll ans=100100100100;

    for(int i=0;i<n-k+1;i++){
        ll l=x[i];
        ll r=x[i+k-1];
        ans=min(ans, abs(l)+abs(r-l));
        ans=min(ans, abs(r)+abs(r-l));
    }
    cout<<ans<<endl;

    return 0;

}
