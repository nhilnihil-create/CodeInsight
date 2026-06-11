#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define deb(x) cout << #x << "=" << x << endl;
const int N = 3e3+7;
string s,t; int n,m;
int dp[N][N];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> s >> t; n = s.size(); m = t.size();
    for (int i = 1; i <= n; i++) {
        dp[i][0]=0; dp[0][i]=0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i-1]==t[j-1]) {
                dp[i][j]=dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    // cout << dp[n][m] << endl;
    int tot = dp[n][m];
    vector<int> vals(tot);
    int i = n, j =m;
    
    while (j>0||i>0) {
        if (i>0&&j>0 && s[i-1]==t[j-1]) {
            vals[--tot]=s[i-1];
            i--; j--;
        } else if (i==0 || (j>0 && dp[i][j-1] > dp[i-1][j])) {
            j--;
        } else {
            i--;
        }
    }
    for (char c : vals) cout << c;
    if (vals.size() > 0) cout << endl;

    return 0;
}
