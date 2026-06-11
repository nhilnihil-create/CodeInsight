/*
 * Created by KeigoOgawa
 */


#include <cstdio>
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <cassert>
#include <cmath>

#define INF (int)1e8
#define EPS 1e-10
#define FOR(i, a, b) for (ll i = (a); i < (b); i++)
#define RFOR(i, a, b) for (ll i = (b)-1; i >= (a); i--)
#define REP(i, n) for (ll i = 0; i < (n); i++)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; i--)
#define MIN(a, b) (a > b ? b : a)
#define MAX(a, b) (a > b ? a : b)
#define debug(x) cerr << #x << ": " << x << endl
#define all(a) (a).begin(), (a).end()

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> PII;

// vector
template<typename T> ostream& operator<<(ostream& s, const vector<T>& v) {
    int len = v.size();
    for (int i = 0; i < len; ++i) {
        s << v[i]; if (i < len - 1) s << "\t";
    }
    return s;
}

// 2 dimentional vector
template<typename T> ostream& operator<<(ostream& s, const vector< vector<T> >& vv) {
    int len = vv.size();
    for (int i = 0; i < len; ++i) {
        s << vv[i] << endl;
    }
    return s;
}

ll N, C;


int main(void) {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    vector<ll> x;
    vector<ll> v;
    REP(i, N) {
        ll tx, tv;
        cin >> tx >> tv;
        x.push_back(tx);
        v.push_back(tv);
    }

    ll ans = 0;

    // 初期位置をO，描く円弧の両端をA，Bとする
    // OA + 2OB or OB + 2OA の大きい方が解となる

    ll vsum = 0;
    vector<ll> ga(N+1), gb(N+1);
    ga[N] = gb[N] = 0;

    for (int i = N - 1; i >= 0; i--) {
        vsum += v[i];
        ga[i] = MAX(ga[i + 1], vsum - (C - x[i])); // OB
        gb[i] = MAX(gb[i + 1], vsum - (C - x[i]) * 2); // 2OB
    }

    ans = max(ga[0], gb[0]);
    vsum = 0;

    REP(i, N) {
        vsum += v[i];
        ans = MAX(ans, vsum - x[i] * 2 + ga[i + 1]); // 2OA + OB
        ans = MAX(ans, vsum - x[i] + gb[i + 1]); // OA + 2OB
    }

    cout << ans << endl;
    return 0;
}
