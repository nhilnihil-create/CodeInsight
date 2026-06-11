#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define FORR(i, m, n) for (int i = (m); i >= (n); i--)
#define REP(i, n) FOR(i, 0, n)
#define REPR(i, n) FORR(i, n - 1, 0)
#define REP1(i, n) FOR(i, 1, (n) + 1)
#define ALL(c) (c).begin(), (c).end()
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true;} return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true;} return false;}
const int MOD = 1000000007;
const int INF = 1000000001;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> t(n, vector<int>());
    vector<int> d(n, 0);
    int a, b;
    REP(i, n - 1 + m) {
        cin >> a >> b;
        a--; b--;
        t[a].push_back(b);
        d[b]++;
    }

    vector<int> ans(n);
    deque<int> q;
    REP(i, n) if (d[i] == 0) {
        ans[i] = -1;
        q.emplace_back(i);
    }

    while (!q.empty()) {
        int x = q.front(); q.pop_front();
        for (int y : t[x]) {
            d[y]--;
            if (d[y] == 0) {
                ans[y] = x;
                q.push_back(y);
            }
        }
    }
    for (int i : ans) cout << i + 1 << endl;
}
