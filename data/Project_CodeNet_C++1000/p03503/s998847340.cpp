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

ll f[100][10];
ll p[100][11];

int main(){
    ll n;
    cin >> n;
    rep(i,n){
        rep(j,10){
            cin >> f[i][j];
        }
    }
    rep(i,n){
        rep(j,11){
            cin >> p[i][j];
        }
    }
    ll ans=-INF;
    for(ll i=1;i<(1<<10);i++){
        ll sum=0;
        rep(j,n){
            ll cnt=0;
            rep(k,10){
                if((i>>k)%2==1 && f[j][k]==1) cnt++;
            }
            sum+=p[j][cnt];
        }
        ans=max(ans,sum);
    }
    cout << ans << endl;
    return 0;
}
