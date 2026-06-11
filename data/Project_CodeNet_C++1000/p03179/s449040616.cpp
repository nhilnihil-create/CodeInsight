#include <bits/stdc++.h>
#define ull uint64_t
#define ll long long int
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mx5 100005
#define mx6 1000005
#define mod 1000000007
#define nfs ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

ll dp[3005][3005] = {};

int main() {
    nfs
    ll total = 0;
    int i, j, n;
    string s;
    
    cin >> n >> s;
    
    dp[n][1] = 1;
    for (i = n-1; i; i--) {
        ll part = 0;
        if (s[i-1] == '>') {
            for (j = 1; j <= n-i+1; j++) {
                dp[i][j] = part;
                part = (part + dp[i+1][j]) % mod;
            }
        }
        else {
            for (j = n-i+1; j; j--) {
                dp[i][j] = part;
                part = (part + dp[i+1][j-1]) % mod;
            }
        }
    }

    for (j = 1; j <= n; j++) {
        total =  (total + dp[1][j]) % mod;
    }
    
    cout << total;

}