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

    nxt2(int, N, K);
    vi h(N);
    generate(all(h), nxt<int>);

    vi dp(N);
    for (int i = 1; i < N; i++) {
        dp[i] = INT_MAX;
        for (int j = max(0, i - K); j < i; j++) {
            dp[i] = min(dp[i], dp[j] + abs(h[i] - h[j]));
        }
    }

    cout << dp[N - 1] << endl;

    return 0;
}
