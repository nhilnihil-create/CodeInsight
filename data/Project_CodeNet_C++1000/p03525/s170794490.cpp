#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<ll, P>IP;
typedef vector<ll> V;
typedef vector<V> V2;
typedef vector<vector<P> > G;
void g_dir(G &graph, ll a, ll b, ll w = 1){graph[a].push_back(P(b, w));}
void g_undir(G &graph, ll a, ll b, ll w = 1){g_dir(graph, a, b, w);g_dir(graph, b, a, w);}
#define rep(i, n) for(ll (i) = 0; (i) < (n); (i)++)
#define rep1(i, n) for(ll (i) = 1; (i) <= (n); (i)++)
#define rrep(i, n) for(ll (i) = (n) - 1; (i) >= 0; (i)--)
#define rrep1(i, n) for(ll (i) = (n); (i) >= 1; (i)--)
template<class T> void chmax(T &a, const T &b){if(a < b){a = b;}}
template<class T> void chmin(T &a, const T &b){if(a > b){a = b;}}
const ll INF = 1145141919;
const ll MOD = 1000000007;
const ll NUM = 101010;

int main(){

    ll N;
    cin >> N;
    V cnt(13, 0);
    cnt[0] = 1;
    rep(i, N){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    ll flg = 0;
    if(cnt[0] >= 2 || cnt[12] >= 2)flg = 1;
    rep(i, 13)if(cnt[i] >= 3)flg = 1;
    if(flg){
        cout << 0 << endl;
        return 0;
    }
    ll ans = 0;
    rep(i, 1 << 13){
        V v(25, 0);
        rep(j, 13){
            ll a = j, b = 24 - j;
            if(cnt[j] == 0)continue;
            if(cnt[j] == 2){
                v[a] = 1;
                v[b] = 1;
                continue;
            }
            if(i & (1 << j))v[a] = 1;
            else v[b] = 1;
        }
        ll tmp = 999;
        rep(j, 25)rep(k, 25)if(v[j] && v[k] && j != k)chmin(tmp, min(abs(j - k), 24 - abs(j - k)));
        chmax(ans, tmp);
    }
    cout << ans << endl;
    
    return 0;
}