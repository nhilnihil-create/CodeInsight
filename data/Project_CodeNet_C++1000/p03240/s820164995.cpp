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
 
const ll mod=1234567;
 
int main(){
    ll n;
    cin >> n;
    vector<ll> x(n),y(n),h(n);
    rep(i,n){
        cin >> x[i] >> y[i] >> h[i];
    }
    ll ans_x,ans_y,ans_h;
    for(ll i=0;i<=100;i++){
        for(ll j=0;j<=100;j++){
            set<ll> s;
            rep(k,n){
                if(h[k]>0){
                    s.insert(h[k]+abs(x[k]-i)+abs(y[k]-j));
                }
            }
            if(s.size()==1){
                ll v=*s.begin();
                bool ok=true;
                rep(k,n){
                    if(h[k]==0 && v-abs(x[k]-i)-abs(y[k]-j)>0){
                        ok=false;
                    }
                }
                if(ok){
                    ans_x=i;
                    ans_y=j;
                    ans_h=v;
                }
            }
        }
    }
    cout << ans_x << " " << ans_y << " " << ans_h << endl;
    return 0;
}