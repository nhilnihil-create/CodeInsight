#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
typedef pair<int, int> P;
typedef pair<long long, long long> Pll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vll;
typedef vector<vector<long long>> vvll;
const long long INF = 1LL << 60;
const int INT_INF = 1 << 30;
const double PI = acos(-1.0);

int N, A, B, C;

ll dfs(int i, int a, int b, int c, vi &l) {
    if (i == N) {
        if (!a || !b || !c) return INF;
        return abs(a - A) + abs(b - B) + abs(c - C);
    }
    ll ret = dfs(i + 1, a, b, c, l);

    ret = min(ret, dfs(i + 1, a + l.at(i), b, c, l) + (a ? 10 : 0));
    ret = min(ret, dfs(i + 1, a, b + l.at(i), c, l) + (b ? 10 : 0));
    ret = min(ret, dfs(i + 1, a, b, c + l.at(i), l) + (c ? 10 : 0));

    return ret;
}

int main() {
    cin >> N >> A >> B >> C;
    vi l(N);
    rep(i, N) { cin >> l.at(i); }
    cout << dfs(0, 0, 0, 0, l) << endl;
}
