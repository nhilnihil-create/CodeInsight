#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int mod = 1e9 + 7;
const int MAX = 510000;
const int V = 100005;
ll dy[8] = {1,0,-1,0,1,-1,1,-1};
ll dx[8] = {0,1,0,-1,1,-1,-1,1};

bool between(ll a, ll b, ll x){
    if(a > b) return b <= x && x <= a;
    else return a <= x && x <= b;
}

int main(){
    ll n,K; cin >> n >> K;
    vpl p(n);
    rep(i,n) cin >> p[i].first >> p[i].second;
    ll ans = linf;
    rep(i,n){
        REP(j,i+1,n){
            REP(k,j+1,n){
                REP(l,k+1,n){
                    ll cnt = 0;
                    ll x = min({p[i].first,p[j].first,p[k].first,p[l].first});
                    ll X = max({p[i].first,p[j].first,p[k].first,p[l].first});
                    ll y = min({p[i].second,p[j].second,p[k].second,p[l].second});
                    ll Y = max({p[i].second,p[j].second,p[k].second,p[l].second});
                    rep(m,n){
                        if(between(x,X,p[m].first) && between(y,Y,p[m].second)) cnt++;
                    }
                    if(cnt >= K) ans = min(ans, (X-x)*(Y-y));
                }
            }
        }
    }
    rep(i,n){
        REP(j,i+1,n){
            REP(k,j+1,n){
            ll cnt = 0;
            ll x = min({p[i].first,p[j].first,p[k].first});
            ll X = max({p[i].first,p[j].first,p[k].first});
            ll y = min({p[i].second,p[j].second,p[k].second});
                ll Y = max({p[i].second,p[j].second,p[k].second});
                rep(m,n){
                    if(between(x,X,p[m].first) && between(y,Y,p[m].second)) cnt++;
                }
                if(cnt >= K) ans = min(ans, (X-x)*(Y-y));
            }
        }
    }
    rep(i,n) {
        REP(j, i + 1, n) {
            ll cnt = 0;
            ll x = min(p[i].first, p[j].first);
            ll X = max(p[i].first, p[j].first);
            ll y = min(p[i].second, p[j].second);
            ll Y = max(p[i].second, p[j].second);
            rep(m, n) {
                if (between(x, X, p[m].first) && between(y, Y, p[m].second)) cnt++;
            }
            if (cnt >= K) ans = min(ans, (X - x) * (Y - y));
        }
    }
    cout << ans << endl;
}
