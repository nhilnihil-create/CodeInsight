#include <bits/stdc++.h>
using namespace std;

#define ull unsigned long long
#define endl '\n'
#define ll long long
const int N = 3e3 + 5;
ll mod = 1e9 + 7;
ll dp[N][N];
int main(){
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        if (fopen("VLJUM.INP", "r")){
                freopen("VLJUM.INP", "r", stdin);
                freopen("VLJUM.OUT", "w", stdout);
        }
        ll n;
        cin >> n;
        string s;
        cin >> s;
        s = "  " + s;
        dp[1][1] = 1;
        for (int i = 2; i <= n; i++){
                if (s[i] == '>') {
                        ll mem = 0;
                        for (int j = i - 1; j >= 1; j--){
                                mem = (mem + dp[i - 1][j]) % mod;
                                dp[i][j] = mem;
                        }
                } else {
                        ll mem = 0;
                        for (int j = 1; j < i; j++){
                                mem = (mem + dp[i - 1][j]) % mod;
                                dp[i][j + 1] = mem;
                        }
                }
        }
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans = (ans + dp[n][i]) % mod;
        cout << ans;
}
/*
*/
