
//#pragma GCC target("avx2")
#pragma GCC optimize("O3")
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

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n, q;
    cin >> n >> q;

    string s;
    cin >> s;

    vector<char> l(q), d(q);
    REP(i, q) cin >> l[i] >> d[i];

    //left
    int ok = -1, ng = s.size();
    while (ng - ok > 1) {
        int mid = (ng + ok) / 2;

        int cur = mid;
        REP(i, q) {
            if (s[cur] != l[i]) continue;

            if (d[i] == 'L') cur--;
            else cur++;

            if (cur == -1 || cur == s.size()) break;
        }

        if (cur == -1) ok = mid;
        else ng = mid;
    }

    ll ans = ok + 1;

    // right
    reverse(ALL(s));
    ok = -1, ng = s.size();
    while (ng - ok > 1) {
        int mid = (ng + ok) / 2;

        int cur = mid;
        REP(i, q) {
            if (s[cur] != l[i]) continue;

            if (d[i] == 'L') cur++;
            else cur--;

            if (cur == -1 || cur == s.size()) break;
        }

        if (cur == -1) ok = mid;
        else ng = mid;
    }

    ans += ok + 1;

    print(n - ans);
}
