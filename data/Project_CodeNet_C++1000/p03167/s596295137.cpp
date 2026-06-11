#include <bits/stdc++.h>
#define ll long long
#define all(x) x.begin(), x.end()
#define M 1000000007
using namespace std;

int h, w;
vector<string> g;

bool isValid(int i, int j) {
    return (i >= 0 && i < h && j >= 0 && j < w && g[i][j] == '.');
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> h >> w;
    for(int i = 0; i < h; i++) {
        string s; cin >> s;
        g.push_back(s);
    }
    vector<vector<long long>> dp(h, vector<long long> (w, 0));
    dp[0][0] = 1;
    for(int i = 0; i < h; i++) {
        for(int j = 0; j < w; j++) {
            ll a = (isValid(i-1, j)?dp[i-1][j]:0);
            ll b = (isValid(i, j-1)?dp[i][j-1]:0);
            dp[i][j] = max(dp[i][j], (a%M+b%M)%M);
        }
    }

    cout << dp[h-1][w-1] << '\n';
}
