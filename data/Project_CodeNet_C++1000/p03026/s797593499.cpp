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
    int N;
    vector<int> a, b, c;
    void input() {
        cin >> N;
        a.resize(N - 1);
        b.resize(N - 1);
        REP(i, N - 1) {
            cin >> a[i] >> b[i];
            --a[i];
            --b[i];
        }
        c.resize(N);
        REP(i, N) { cin >> c[i]; }
    }
    void output() {
        vector<int> copy = c;
        SORTR(c);
        vector<vector<int>> edge(N);
        vector<P> count(N);
        REP(i, N) { count[i] = {0, i}; }
        REP(i, N - 1) {
            edge[a[i]].emplace_back(b[i]);
            edge[b[i]].emplace_back(a[i]);
            count[a[i]].first++;
            count[b[i]].first++;
        }
        SORTR(count);
        vector<int> d(N, -1);
        int s = count[0].second;
        d[s] = c[0];
        int k = 1;
        queue<int> qu;
        qu.emplace(s);
        while (!qu.empty()) {
            int i = qu.front();
            qu.pop();
            for (auto &j : edge[i]) {
                if (d[j] < 0) {
                    d[j] = c[k++];
                    qu.emplace(j);
                }
            }
        }
        int res = 0;
        REP(i, N - 1) { res += c[i + 1]; }
        cout << res << endl;
        REP(i, N) { cout << d[i] << " "; }
        cout << endl;
    }

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
