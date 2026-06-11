#include <bits/stdc++.h>
#define ALL(A) (A).begin(), (A).end()
#define ll long long
#define rep(i, n) for (int i = 0; i < (n); i++)

using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }

const ll mod = 1e9 + 7;
const ll INF = -1 * ((1LL << 63) + 1);
const int inf = -1 * ((1 << 31) + 1);

ll dp[(int)2e5+2];

int main(void){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    ll ans = 1;
    vector<int> c(n);
    vector<vector<int>> g(2e5+2);
    rep(i,n){
        cin >> c[i];
        g[c[i]].push_back(i);
    }
    dp[0] = 1;
    for(int i=1;i<=n;i++){
        dp[i-1]%=mod;
        dp[i]%=mod;
        (dp[i] += dp[i-1])%mod;


        int color = c[i-1];

        int it = lower_bound(ALL(g[color]),i-1) - g[color].begin();
        if(it > 0){
            int j = g[color][it-1];
            if((i-1) - j > 1){
                (dp[i] += dp[j+1]);
                dp[i]%=mod;
                dp[j+1]%=mod;
            }
        }
    }
    cout << dp[n]%mod << endl;
}