#include<bits/stdc++.h>
#define N 2000009
#define ll long long
#define ld long double
#define ff first
#define ss second
#define inf 1000000005
#define mod 1000000007
using namespace std;
ll n, dp[3001][3001], ans, p[3001];
string s;
int main() {
    cin>>n>>s;
    dp[1][1] = 1;
    for(int i=2;i<=n;i++) {
        for(int j=1;j<i;j++)
            p[j] = (dp[i - 1][j] + p[j - 1]) % mod;
        for(int last=1;last<=i;last++) {
            int l = last, r = i - 1;
            if(s[i - 2] == '<') {
                l = 1;
                r = last - 1;
            }
            dp[i][last] += (p[r] - p[l - 1]);
            if(dp[i][last] < mod)
                dp[i][last] += mod;
            if(i == n) {
                ans += dp[i][last];
                ans %= mod;
            }
        }
    }
    cout<<ans;
}
