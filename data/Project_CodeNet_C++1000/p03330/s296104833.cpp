// template version 1.15
using namespace std;
#include <bits/stdc++.h>

// varibable settings
#define int long long
const int INF=1e18;

// define basic macro {{{
#define _overload3(_1,_2,_3,name,...) name
#define _rep(i,n) repi(i,0,n)
#define repi(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define rep(...) _overload3(__VA_ARGS__,repi,_rep,)(__VA_ARGS__)
#define _rrep(i,n) rrepi(i,0,n)
#define rrepi(i,a,b) for(int i=(int)((b)-1);i>=(int)(a);--i)
#define rrep(...) _overload3(__VA_ARGS__,rrepi,_rrep,)(__VA_ARGS__)
#define each(i,a) for (auto&& i : a)
#define all(x) (x).begin(),(x).end()
#define sz(x) ((int)(x).size())
#define pb(a) push_back(a)
#define mp(a, b) make_pair(a, b)
#define mt(a, b, c) make_tuple(a, b, c)
#define ub upper_bound
#define lb lower_bound
#define posl(A, x) (lower_bound(all(A), x)-A.begin())
#define posu(A, x) (upper_bound(all(A),x)-A.begin())
template<class T> inline void chmax(T &a, const T &b) { if((a) < (b)) (a) = (b); }
template<class T> inline void chmin(T &a, const T &b) { if((a) > (b)) (a) = (b); }

#define divceil(a,b) ((a)+(b)-1)/(b)
#define is_in(x, a, b) ((a)<=(x) && (x)<(b))
#define uni(x) sort(all(x));x.erase(unique(all(x)),x.end())
#define slice(l, r) substr(l, r-l)

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef long double ld;
typedef pair<int,int> pii;
typedef tuple<int,int,int> iii;

template<typename T> using PQ = priority_queue<T, vector<T>, greater<T>>;
struct Fast { Fast(){ std::cin.tie(0); ios::sync_with_stdio(false); } } fast;

#if defined(PCM) || defined(LOCAL)
    #include "lib/dump.hpp"
#else
    #define dump(...) 42
    #define dump_1d(...) 42
    #define dump_2d(...) 42
    #define cerrendl 42
#endif
//}}}

signed main() {
    int n,c;cin>>n>>c;

    vvi d(c, vi(c));
    rep(i, c)rep(j, c) cin>>d[i][j];
    dump_2d(d, c, c);

    vvi g(n, vi(n));
    rep(i, n)rep(j, n) cin>>g[i][j];
    dump_2d(g, n, n);

    vvi t(3);
    rep(i, n)rep(j, n){
        t[(i+j)%3].pb(g[i][j]);
    }

    rep(i, 3){
        dump(t[i]);
    }

    // vector<int> used(c+1);
    // vi cs;
    // auto dfs = [&](const auto& dfs, int p) -> void {
    //     rep(i, 1, c+1){
    //         if (used[i]) continue;
    //         cs.pb(i);
    //         used[i] = true;
    //
    //         if (p<2) dfs(dfs, p+1);
    //         else {
    //             dump(cs);
    //         }
    //         used[i] = false;
    //         cs.pop_back();
    //     }
    // };
    // dfs(dfs, 0);

    int ans = INF;

    vvi cost(3, vi(c+1));
    rep(i, 3)rep(j, 1, c+1){
        each(el, t[i]) cost[i][j] += d[el-1][j-1];
    }

    rep(i, 1, c+1){
        rep(j, 1, c+1){
            rep(k, 1, c+1){
                if (i==j || j==k || k==i) continue;

                int res = 0;
                res += cost[0][i];
                res += cost[1][j];
                res += cost[2][k];
                chmin(ans, res);
            }
        }
    }
    cout << ans << endl;

    return 0;
}
