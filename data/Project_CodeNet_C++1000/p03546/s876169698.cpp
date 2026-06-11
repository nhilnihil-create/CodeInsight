// https://atcoder.jp/contests/abc079/tasks/abc079_d
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <map>
#include <unordered_map>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <bitset>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;
#define REP(i, n) for(size_t i = 0; i < (n); ++i)

int main()
{
    int H, W;
    vector<vector<int>> c(10, vector<int>(10));
    cin >> H >> W;
    REP(i, 10) REP(j, 10) cin >> c[i][j];
    vector<vector<int>> A(H, vector<int>(W));
    REP(i, H) REP(j, W) cin >> A[i][j];

    // Warchall-Floyed 法を用いて最小コストを求める
    REP (k, 10) // 中継する番号
    REP (i, 10) // スタート番号
    REP (j, 10) // ゴール番号
    {
        c[i][j] = min(c[i][j], c[i][k] + c[k][j]);
    }

    int ans = 0;
    REP (i, H) REP(j, W)
    {
        if (-1 < A[i][j])
        {
            ans += c[A[i][j]][1];
        }
    }
    cout << ans << endl;
    return 0;
}
