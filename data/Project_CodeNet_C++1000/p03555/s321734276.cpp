#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <cmath>
#include <iomanip>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
using namespace std;
using ll = long long;
constexpr ll INF = 3000000000000000000;

int main() {
    vector<vector<char>> C(2, vector<char>(3));
    REP(i, 2) REP(j, 3) cin >> C[i][j];
    if (C[0][0] == C[1][2] && C[0][1] == C[1][1] && C[0][2] == C[1][0]) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}
