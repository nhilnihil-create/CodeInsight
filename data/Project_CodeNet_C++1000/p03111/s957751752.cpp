#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i, n) for (int i = 0; i < (n); i++)
using pint = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

int n, a, b, c;
int A[10];
int ans = inf;

void calc (vector<int> v) {
    vector<vector<int>> ans_sum (3);
    rep (i, n) {
        if (v[i] == 3) continue;
        ans_sum[v[i]].push_back (A[i]);
    }
    int sum = 0;
    int cnt[3] = {};
    rep (i, 3) {
        if (ans_sum[i].size() == 0) return;
        sum += 10 * (ans_sum[i].size() - 1);
        rep (j, ans_sum[i].size()) { cnt[i] += ans_sum[i][j]; }
    }
    sort (cnt, cnt + 3);
    sum += abs (c - cnt[0]) + abs (b - cnt[1]) + abs (a - cnt[2]);
    ans = min (ans, sum);
}

void dfs (int depth, vector<int> &v) {
    if (depth == n) {
        calc (v);
        return;
    }

    rep (i, 4) {
        v[depth] = i;
        dfs (depth + 1, v);
    }
}

int main() {
    cin >> n >> a >> b >> c;
    rep (i, n) cin >> A[i];
    vector<int> v (n);
    dfs (0, v);
    cout << ans << "\n";
}