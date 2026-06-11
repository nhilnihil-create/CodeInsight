#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REPR(i, n) for (int i = n - 1; i >= 0; --i)
#define FOR(i, a, b) for (int i = a; i < b; ++i)
#define FORR(i, a, b) for (int i = b - 1; i >= a; --i)
#define SORT(v) sort(v.begin(), v.end())
#define SORTR(v) sort(v.rbegin(), v.rend())
#define REV(v) reverse(v.begin(), v.end())
#define ITER(itr, v) for (auto itr = v.begin(); itr != v.end(); ++itr)
#define LB(v, x) (lower_bound(v.begin(), v.end(), x) - v.begin())
#define UB(v, x) (upper_bound(v.begin(), v.end(), x) - v.begin())
#define SZ(v) (int)v.size()
using namespace std;
using ll = long long;
using P = pair<int, int>;

class Main {
    int N, A, B, C;
    vector<int> l;
    int dfs(int i, int a, int b, int c) {
        if (i == N) {
            if (a == 0 || b == 0 || c == 0) return 10000;
            int res = 0;
            res += abs(a - A);
            res += abs(b - B);
            res += abs(c - C);
            return res;
        }
        int res = 10000;
        res = min(res, dfs(i + 1, a, b, c));
        res = min(res, dfs(i + 1, a + l[i], b, c) + 10 * (a > 0));
        res = min(res, dfs(i + 1, a, b + l[i], c) + 10 * (b > 0));
        res = min(res, dfs(i + 1, a, b, c + l[i]) + 10 * (c > 0));
        return res;
    }
    void input() {
        cin >> N >> A >> B >> C;
        l.resize(N);
        REP(i, N) { cin >> l[i]; }
    }
    void output() { cout << dfs(0, 0, 0, 0) << endl; }

public:
    Main() {
        input();
        output();
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    Main();

    return 0;
}
