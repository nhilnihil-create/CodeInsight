#include<bits/stdc++.h>
#define int long long
#define ll long long
#define fi first
#define se second
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
using namespace std;
string s,t;
const int N = 3e3+5;
int dp[N][N];
pii p[N][N];
main() {
    ios::sync_with_stdio(0);
    cin >> s >> t;
    s = "@" + s;
    t = "%" + t;
    int n = s.size() - 1;
    int m = t.size() - 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            if (s[i] == t[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                p[i][j] = {i-1,j-1};
            }else {
                if (dp[i-1][j] < dp[i][j-1]) {
                    dp[i][j] = dp[i][j-1];
                    p[i][j] = {i,j-1};
                }
                else {
                    dp[i][j] = dp[i-1][j];
                    p[i][j] = {i-1,j};
                }
            }
        }
    string ans;
    for (int a = n,b = m; a && b;) {
        if (s[a] == t[b]) ans+=s[a];
        pii x = p[a][b];
        a = x.first;
        b = x.second;
    }
    reverse(ans.begin(),ans.end());
    cout << ans;
}
