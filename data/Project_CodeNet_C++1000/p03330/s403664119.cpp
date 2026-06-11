#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pli = pair<ll, int>;
using Graph = vector<vector<pii>>;
const int MOD = 1e9 + 7;

int N, C;
vector<vector<int>> D;
vector<vector<int>> cnt;

int a[3];
int rec(int d = 0) {
    int res = INT_MAX;
    if (d >= 3) {
        if (a[0] == a[1] || a[1] == a[2] || a[2] == a[0])
            return res;
        res = 0;
        for (int i = 0; i < 3; ++i)
            for (int j = 0; j < C; ++j)
                res += D[j][a[i]] * cnt[i][j];
        return res;
    }

    for (int i = 0; i < C; ++i) {
        a[d] = i;
        res = min(res, rec(d + 1));
    }
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    cin >> N >> C;
    D.resize(C, vector<int>(C));
    cnt.resize(3, vector<int>(C));
    for (int i = 0; i < C; ++i)
        for (int j = 0; j < C; ++j)
            cin >> D[i][j];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            int c;
            cin >> c;
            c--;
            cnt[(i + j) % 3][c]++;
        }
    }

    cout << rec() << endl;

    return 0;
}
