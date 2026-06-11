#pragma GCC optimize ("O3")

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
typedef uint64_t ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<ll,ll> Pll;
typedef pair<int,int> Pin;

ll INF = 1e16;
int inf = 1e9;

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n; cin >> n;

    vi t(n);

    REP(i, n) {
        cin >> t[i];
    }

    set<int> dp;
    dp.insert(1 << 0);

    REP(i, n) {
        int c1 = t[i], c2 = 24 - t[i];
        if (c2 == 24) c2 = 0;
        set<int> tmp;
        for(auto &e: dp) {
            if (!(e >> c1 & 1)) tmp.insert(e | 1 << c1);
            if (!(e >> c2 & 1)) tmp.insert(e | 1 << c2);
        }

        dp.swap(tmp);
    }

    int ans = 0;
    for(auto &e: dp) {
        int tmp = 24;
        REP(j, 24) REP(k, 24) {
            if (j == k || !(e >> j & 1) || !(e >> k & 1)) continue;
            tmp = min(tmp, min(abs(j - k), 24 - abs(j - k)));
        }

        ans = max(tmp, ans);
    }

    print(ans);
}
