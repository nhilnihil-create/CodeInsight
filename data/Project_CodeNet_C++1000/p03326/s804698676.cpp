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

int main(){
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> a(n,vector<ll>(3));
    rep(i,n){
        rep(j,3){
            cin >> a[i][j];
        }
    }
    
    ll ans=-INF;
    for(ll i=0;i<(1<<3);i++){
        vector<ll> sum(n);
        ll tot=0;
        rep(j,3){
            if((i>>j)%2==1){
                rep(k,n){
                    a[k][j]*=-1;
                }
            }
        }
        rep(j,n){
            rep(k,3){
                sum[j]+=a[j][k];
            }
        }
        sort(sum.rbegin(),sum.rend());
        rep(j,m){
            tot+=sum[j];
        }
        ans=max(ans,tot);
        rep(j,3){
            if((i>>j)%2==1){
                rep(k,n){
                    a[k][j]*=-1;
                }
            }
        }
    }
    cout << ans << endl;
} 
