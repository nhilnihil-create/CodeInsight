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

const ll INF=1e9+7;


int main(){
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n),sum(n+1);
    rep(i,n){
        cin >> a[i];
        sum[i+1]=sum[i]+a[i];
    }
    vector<ll> bt;
    for(ll i=0;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            bt.push_back(sum[j]-sum[i]);
        }
    }
    vector<ll> buf;
    ll ans=0;
    for(ll i=40;i>=0;i--){
        ll cnt=0;
        rep(j,bt.size()){
            if((bt[j]>>i)%2==1){
                cnt++;
                buf.push_back(bt[j]);
            }
        }
        if(cnt>=k){
            bt=vector<ll>(cnt);
            bt=buf;
            ans+=1LL<<i;
        }
        buf.clear();
    }
    cout << ans << endl;
}