#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep(i,n) for(ll i=0;i<(n);i++)
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define fi first
#define se second
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))

using namespace std;

template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}

const ll INF=1e18;
const ll mod=1e9+7;
const double eps=0.000000001;

int main(){
    ll n;
    cin >> n;
    string s;
    cin >> s;
    vector<ll> dp1(n+1),dp2(n+1);
    for(ll i=1;i<=n;i++){
        if(s[i-1]=='#') dp1[i]=dp1[i-1]+1;
        else dp1[i]=dp1[i-1];
    }
    for(ll i=n;i>=1;i--){
        if(s[i-1]=='#') dp2[i-1]=dp2[i]+1;
        else dp2[i-1]=dp2[i];
    }
    for(ll i=0;i<=n;i++){
        //cout << dp1[i] << " " << dp2[i] << endl;
    }
    ll ans=INF;
    for(ll i=0;i<=n;i++){
        ans=min(ans,dp1[i]+min(dp2[i],n-i-dp2[i]));
    }
    cout << ans << endl;
    return 0;
}
