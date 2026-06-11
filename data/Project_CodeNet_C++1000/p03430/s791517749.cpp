#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define p_ary(ary,a,b) do { cout << "["; for (int count = (a);count < (b);++count) cout << ary[count] << ((b)-1 == count ? "" : ", "); cout << "]\n"; } while(0)
#define p_map(map,it) do {cout << "{";for (auto (it) = map.begin();;++(it)) {if ((it) == map.end()) {cout << "}\n";break;}else cout << "" << (it)->first << "=>" << (it)->second << ", ";}}while(0)

int main() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(k+1,0)));
    for (int i = 0;i < n;++i) for (int j = 0;j < k+1;++j) dp[i][i+1][j] = 1;
    for (int i = 2;i <= n;++i) {
        for (int j = 0;j < n+1-i;++j) {
            if (s[j] == s[j+i-1]) for (int l = 0;l < k+1;++l) dp[j][j+i][l] = max({dp[j+1][j+i-1][l]+2,dp[j][j+i-1][l],dp[j+1][j+i][l]});
            else for (int l = 0;l < k+1;++l) dp[j][j+i][l] = max(dp[j][j+i-1][l],dp[j+1][j+i][l]);
        }
        for (int j = 0;j < n+1-i;++j) {
            for (int l = 0;l < k;++l) dp[j][j+i][l+1] = max({dp[j][j+i][l+1],dp[j+1][j+i-1][l]+2});
        }
    }
    cout << dp[0][n][k] << endl;
}