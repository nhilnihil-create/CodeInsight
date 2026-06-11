#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,j,k) for(int i=j;i<k;i++)
#define f(n) fr(i,0,n)
#define f1(n) fr(i,1,n+1)
#define pb push_back
#define F first
#define S second
#define all(x) x.begin(), x.end()
const int mod = 1e9+7;
const int maxn = 250005;

void go() {
    int n;
    cin >> n;
    int dp[n+1][n+1] = {};
    f(n) {
        dp[0][i] = 1;
    }
    string s;
    cin >> s;
    s = " " + s;
    f1(n - 1) {
        if (s[i] == '<') {
            for (int j = 1 ; j <= i ; j++) {
                dp[i][j] = (dp[i][j - 1] + dp[i - 1][j - 1]) % mod;
            }
        }
        else {
            for (int j = i - 1 ; j >= 0 ; j--) {
                dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % mod;
            }
        }
    }
    int ans = 0;
    f(n) {
        ans += dp[n - 1][i];
        ans %= mod;
    }
    cout << ans << '\n';
} 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int c = 0;
    int t;
    if (!c) {
        t = 1;
    }
    else {
        cin >> t;
    }
    while (t--) {
        //cout << "Case #"<<(c++) << ": ";
        go();
    }
    
}