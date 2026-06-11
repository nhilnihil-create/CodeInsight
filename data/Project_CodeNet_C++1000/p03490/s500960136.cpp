#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#define toggle(X) ((X) ? 0 : 1)
using namespace std;
using ll = long long;

string s;
ll x, y;
bool dp[2][8005][2 * 8005];
vector<ll> cmp;

int main() {
    cin >> s;
    cin >> x >> y;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'T') {
            cmp.push_back(-1);
        }
        else {
            if (cmp.size() == 0 ||
                cmp.back() == -1) {
                cmp.push_back(1);
            }
            else {
                cmp.back()++;
            }
        }
    }

    int sw = 0;
    x += 8005;
    y += 8005;

    if (cmp.front() == -1) {
        sw = 1;
        dp[0][0][8005] = true;
        dp[1][0][8005] = true;
    }
    else {
        dp[0][0][8005 + cmp.front()] = true;
        dp[1][0][8005] = true;
    }

    for (int i = 1; i < cmp.size(); i++) {
        if (cmp[i] == -1) {
            sw = toggle(sw);
            for (int j = 0; j < 2 * 8005; j++) {
                dp[0][i][j] = dp[0][i - 1][j];
                dp[1][i][j] = dp[1][i - 1][j];
            }
            
            continue;
        }

        for (int j = 0; j < 2 * 8005; j++) {
            if (dp[sw][i - 1][j]) {
                dp[sw][i][j + cmp[i]] = true;
                dp[sw][i][j - cmp[i]] = true;
            }

            dp[toggle(sw)][i][j] = dp[toggle(sw)][i - 1][j];
        }
    }
    
    if (dp[0][cmp.size() - 1][x] && dp[1][cmp.size() - 1][y]) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}
