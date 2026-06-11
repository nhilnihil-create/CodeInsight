#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int inf = 1e9;
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, b, a) for (int i = a - 1; i >= b; i--)
using Graph = vector<vector<int>>;
using pint = pair<int, int>;
int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
int dxx[8] = {1, 1, 1, 0, 0, -1, -1, -1}, dyy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

string ans, s;
void dfs (int now, int sum, string t) {
    if (now == 3) {
        if (sum == 7) {
            ans = t;
            // cout << now << ans << "\n";
            return;
        } else {
            return;
        }
    }
    dfs (now + 1, sum + (s[now + 1] - '0'), t + "+");
    dfs (now + 1, sum - (s[now + 1] - '0'), t + "-");
}

int main() {
    cin >> s;
    dfs (0, s[0] - '0', "");
    string anss = "";
    rep (i, 0, 3) { anss = anss + s[i] + ans[i]; }
    anss = anss + s[3] + "=7";
    cout << anss << "\n";
    // cout << ans << "\n";
}