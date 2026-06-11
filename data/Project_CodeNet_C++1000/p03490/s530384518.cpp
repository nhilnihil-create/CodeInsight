#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll INF = 1LL << 60;
const ll MOD = 1e9 + 7;
bool dp[2][8001];

int main() {
    string s;
    cin >> s;
    int x[2];
    cin >> x[0] >> x[1];
    int n = s.size();
    vector<int> v[2];
    bool dir = 0;
    int len = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'F') {
            len++;
        } else {
            v[dir].push_back(len);
            len = 0;
            dir ^= 1;
        }
    }
    v[dir].push_back(len);
    x[0] -= v[0][0];
    v[0].erase(v[0].begin());
    x[0] = abs(x[0]);
    x[1] = abs(x[1]);
    for (int k = 0; k < 2; k++) {
        int sum = 0;
        for (int i = 0; i < v[k].size(); i++) {
            sum += v[k][i];
        }
        if (sum < x[k] || (sum - x[k]) % 2) {
            cout << "No" << endl;
            return 0;
        }
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        for (int i = 0; i < v[k].size(); i++) {
            for (int j = 0; j <= 8000; j++) {
                dp[(i + 1) & 1][j] |= dp[i & 1][j];
                if (j + v[k][i] <= 8000) dp[(i + 1) & 1][j + v[k][i]] |= dp[i & 1][j];
            }
            for (int j = 0; j <= 8000; j++) dp[i & 1][j] = 0;
        }
        if (!dp[v[k].size() & 1][(sum - x[k]) / 2]) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}