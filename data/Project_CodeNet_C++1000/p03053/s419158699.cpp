#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<long long, long long> P;
struct edge{long long to,cost;};
const int inf = 1 << 27;
const long long INF = 1LL << 60;
const int COMBMAX = 1001001;
const long long MOD = 1000000007;
const long long dh[] = {-1, 0, 0, 1}; long long dw[] = {0, -1, 1, 0};
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define eachdo(v, e) for(const auto& e : (v))
#define all(v) (v).begin(), (v).end()
#define lower_index(v, e) (long long)distance((v).begin(), lower_bound((v).begin(), (v).end(), e))
#define upper_index(v, e) (long long)distance((v).begin(), upper_bound((v).begin(), (v).end(), e))
long long gcd(long long a, long long b){return a % b ? gcd(b , a % b) : b;}
long long mpow(long long a, long long n, long long mod = MOD){long long res = 1; while(n > 0){if(n & 1)res = res * a % mod; a = a * a % mod; n >>= 1;} return res;}
void yn(bool j){cout << (j ? "Yes" : "No") << endl; return;}
template<class Head> void pt(Head&& head){cout << head << endl; return;}
template<class Head, class... Tail> void pt(Head&& head, Tail&&... tail){cout << head << " "; pt(forward<Tail>(tail)...);}
template<class T> void debug(T v){rep(i, v.size()) cout << v[i] << " " ; cout << endl;}
template<class T> void debug2(T v){rep(i, v.size()){rep(j, v[i].size()) cout << v[i][j] << " " ; cout << endl;}}
template<class T1, class T2> long long bcount(T1 v, T2 a){return upper_index(v, a) - lower_index(v, a);} 
template<class T1, class T2> inline bool chmin(T1 &a, T2 b){if(a > b){a = b; return true;} return false;}
template<class T1, class T2> inline bool chmax(T1 &a, T2 b){if(a < b){a = b; return true;} return false;}

bool valid(ll mh, ll mw, ll h, ll w){
    return 0 <= h && h < mh && 0 <= w && w < mw;
}

int main(){
    ll H, W; cin >> H >> W;
    vector<vector<char>> m(H, vector<char>(W));
    vector<vector<ll>> d(H, vector<ll>(W, -1));
    queue<pair<P, ll>> que;
    rep(i, H) rep(j, W) cin >> m[i][j];
    rep(i, H) rep(j, W) if(m[i][j] == '#') que.push(make_pair(P(i, j), 0LL));
    while(!que.empty()){
        pair<P, ll> cur = que.front(); que.pop();
        ll ni = cur.first.first;
        ll nj = cur.first.second;
        // pt(ni, nj);
        if (d[ni][nj] != -1) continue;
        d[ni][nj] = cur.second;
        chmin(d[ni][nj], cur.second);
        rep(i, 4){
            if (valid(H, W, ni + dh[i], nj + dw[i])) que.push(make_pair(P(ni + dh[i], nj + dw[i]), cur.second + 1));
        }
    }
    ll ans = 0;
    rep(i, H) rep(j, W) chmax(ans, d[i][j]);
    pt(ans);
}