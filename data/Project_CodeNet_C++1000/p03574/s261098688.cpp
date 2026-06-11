#pragma GCC optimize("O3")
//#pragma GCC target("avx2")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include <prettyprint.hpp>
#define debug(...)  cerr << "[" << #__VA_ARGS__ << "]: ", d_err(__VA_ARGS__);
#else
#define debug(...) 83;
#endif

void d_err() {
    cerr << endl;
}

template <typename H, typename... T>
void d_err(H h, T... t) {
    cerr << h << " ";
    d_err(t...);
}

template <typename T>
void print(T x) {
    cout << x << "\n";
}

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, m, n) for (int i = (m); i < (n); ++i)
#define REVFOR(i, m, n) for (int i = (n - 1); i >= (m); --i)
#define REP(i, n) FOR(i, 0, n)
#define REVREP(i, n) REVFOR(i, 0, n)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define bcnt __builtin_popcountll

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;
ll MOD = 1e9+7;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int h, w; cin >> h >> w;
    vector<string> m(h);
    REP(i, h) cin >> m[i];

    auto f = [&](int y, int x) -> int {
        int cnt = 0;
        FOR(i, -1, 2) FOR(j, -1, 2) {
            if (i == 0 && j == 0) continue;
            int cy = y + i, cx = x + j;
            if (cy < 0 || cy >= h || cx < 0 || cx >= w) continue;
            cnt += m[cy][cx] == '#';
        }

        return cnt;
    };

    REP(i, h) {
        REP(j, w) {
            if (m[i][j] == '#') cout << "#";
            else cout << f(i, j);
        }
        cout << endl;
    }
}