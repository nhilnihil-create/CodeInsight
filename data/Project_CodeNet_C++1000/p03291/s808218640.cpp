#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

ll add(ll &a, ll b){
    a += b;
    if(a >= MOD) a -= MOD;
    return 0;
}

ll dp[100005][4];

int main(){
    string s;
    cin >> s;

    dp[0][0] = 1;

    rep(i, s.size()){
        rep(j, 4){
            if(s[i] == '?') add(dp[i+1][j], 3 * dp[i][j] % MOD);
            else add(dp[i+1][j], dp[i][j]);
        }

        if(s[i] == '?' || s[i] == 'A') add(dp[i+1][1], dp[i][0]);
        if(s[i] == '?' || s[i] == 'B') add(dp[i+1][2], dp[i][1]);
        if(s[i] == '?' || s[i] == 'C') add(dp[i+1][3], dp[i][2]);
    }

    cout << dp[s.size()][3] << endl;
}