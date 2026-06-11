#include <bits/stdc++.h>
 
using namespace std;
using uint = unsigned int;
using ll = long long;
using ull = unsigned long long;
 
int n, m;
string s, t;
int dp[3030][3030];
bool vis[3030][3030];
 
int solve(int a, int b) {
    if (a == n || b == m) return 0;
    if (vis[a][b]) return dp[a][b];
    vis[a][b] = true;
    int ans1=0, ans2=0;
    if(s[a] == t[b]) ans1 = 1+ solve(a+1, b+1);
    else ans2= max(solve(a+1,b), solve(a, b+1) );
    // int ans = max(solve(a+1, b), solve(a, b+1));
    // if (s[a] == t[b]) ans = max(ans, 1 + solve(a+1, b+1));
    return dp[a][b] = max(ans1, ans2);
}
 
int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    cin >> s >> t;
    n = int(s.size());//4
    m = int(t.size());//5
    int u = solve(0, 0);//3
    int a = 0, b = 0;
    string ans;
    while (u) 
    {// u ==3;
        if (a < n && dp[a+1][b] == u) {// a < 4 && solve() ==3
            a++;
            continue;
        }
        if (b < m && dp[a][b+1] == u) {
            b++;
            continue;
        }
        ans += s[a];
        u--; a++; b++;
    }
    cout << ans << endl;
    return 0;
}