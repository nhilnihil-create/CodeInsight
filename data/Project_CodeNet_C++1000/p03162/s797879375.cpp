// #pragma GCC optimize("O3")
// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace ::std;
// clang-format off
template<typename T> T nxt() {T res; cin >> res; return res;}
#define tests() for (int _ = nxt<int>(); _ >= 0; _--)
#define nxt1(t,n) t (n); cin >> n
#define nxt2(t,n,m) t (n),(m); cin >> n >> m
#define nxt3(t,n,m,k) t (n),(m),(k); cin >> n >> m >> k
#define rep(i, A) for (int i = 0 ; i < A ; i++)
#define ll long long
typedef pair<int,int> pii;typedef pair<ll, ll> pll;typedef vector<int> vi;typedef vector<vi> vvi;typedef vector<ll> vl;typedef vector<vl> vvl;
#define dbg(vari) cerr<<#vari<<" = "<<(vari)<<endl;
template<typename T,typename TT> ostream& operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream& operator<<(ostream &s,vector<T> t){for(T ti : t)s<<ti<<" ";return s; }
#define all(x) (x).begin(), (x).end()
#define last(vec) vec[vec.size()-1]
#define has(c,x) ((c).find(x) != (c).end())
// clang-format on

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N = nxt<int>();

    vector<array<int, 3>> abc(N);

    rep(i, N) {
        nxt3(int, a, b, c);
        abc[i] = {a, b, c};
    }

    int dp[3][N + 1];
    dp[0][0] = 0;
    dp[1][0] = 0;
    dp[2][0] = 0;

    for (int i = 0; i < N; i++) {
        dp[0][i + 1] = abc[i][0] + max(dp[1][i], dp[2][i]);
        dp[1][i + 1] = abc[i][1] + max(dp[0][i], dp[2][i]);
        dp[2][i + 1] = abc[i][2] + max(dp[0][i], dp[1][i]);
    }

    cout << max({dp[0][N], dp[1][N], dp[2][N]}) << endl;

    return 0;
}
