#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <tuple>

using namespace std;
typedef long long ll;

int N;
string S;
int X, Y;
std::vector<int> d;
std::vector<int> dx;
std::vector<int> dy;

bool ok(std::vector<int> &dx, int goal_x, bool y) {
    int m = dx.size();
    vector<unordered_map<int, bool> > dp(m);
    int min, max;
    if (m == 0) return goal_x == 0;
    dp[0][dx[0]] = true;
    min = max = dx[0];
    if (y) {
        dp[0][-dx[0]] = true;
        min = -dx[0];
    }
    for (int i = 1; i < m; i ++) {
        min -= dx[i];
        max += dx[i];
        for (int x = min; x <= max; x ++) {
            dp[i][x] = (dp[i-1][x - dx[i]] || dp[i-1][x + dx[i]]);
        }
    }
    return dp[m-1][goal_x];
}

signed main() {
    getline(cin, S);
    N = S.size();
    cin >> X >> Y;
    int x = 0;
    for (int i = 0; i < N; i ++) {
        if (S[i] == 'T') {
            d.push_back(x);
            x = 0;
        } else if (S[i] == 'F') {
            x ++;
        }
    }
    d.push_back(x);
    int m = d.size();

    for (int i = 0; i < m; i ++) {
        if (i % 2 == 0) {
            dx.push_back(d[i]);
        } else {
            dy.push_back(d[i]);
        }
    }
    cout << (ok(dx, X, false) && ok(dy, Y, true) ? "Yes" : "No") << endl;
    return 0;
}