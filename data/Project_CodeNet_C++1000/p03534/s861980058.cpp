#include <bits/stdc++.h>

using namespace std;

#define llong long long int
#define ldouble long double
#define fore(i, n) for(auto &i : n)
#define rep(i, n) for (int i = 0; i < n; ++i)
#define repr(i, n) for (int i = n; i >= 0; --i) 
#define stl_rep(itr, x) for (auto itr = x.begin(); itr != x.end(); ++itr)
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()

const static int mod = 1000000000 + 7;
const static int inf = INT_MAX / 2;
const static llong INF = LLONG_MAX / 2;
const static double eps = 1e-6;
const static int dx[] = {1, 0, -1, 0};
const static int dy[] = {0, 1, 0, -1};

template<class T> bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}

template<class T> bool chmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return 1;
    }
    return 0;
}

void solve();

signed main (int argc, char *argv[]) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    solve();
    
    return 0;
}

void solve() {
    string S;
    cin >> S;
    map<char, int> M;
    M['a'] = 0;
    M['b'] = 0;
    M['c'] = 0;
    const int n = S.size();
    rep(i, n) ++M[S[i]];

    if (M['a'] == M['b'] && M['b'] == M['c'] && M['a'] == M['c']) {
        cout << "YES" << endl;
    } else {
        int max_cnt = -1, min_cnt = inf;
        rep(i, 3) {
            chmax(max_cnt, M['a' + i]);
            chmin(min_cnt, M['a' + i]);
        }

        if (max_cnt - min_cnt >= 2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
}