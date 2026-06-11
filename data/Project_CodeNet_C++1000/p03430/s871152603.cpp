#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define db double
#define pii pair<int,int>
#define pli pair<ll,int>
#define pil pair<int,ll>
#define pll pair<ll,ll>
#define mat vector<vector<int>>
const int inf = 1 << 30;
const ll linf = 1e18;
const db EPS = 1e-7;
template<class T> void chmin(T& x, T y){if(x > y) x = y;}
template<class T> void chmax(T& x, T y){if(x < y) x = y;}

string S;
int K, dp[310][310][310];
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> S >> K;
    for(int i = 0; i < S.length(); i++) dp[i][i][0] = 1;
    for(int i = 0; i + 1 < S.length(); i++) dp[i][i + 1][S[i] != S[i + 1]] = 2;
    for(int k = 0; k <= K; k++){
        for(int len = 0; len < S.length(); len++){
            for(int l = 0; l + len < S.length(); l++){
                if(l == 0 || l + len - 1 == S.length()) continue;
                if(S[l - 1] == S[l + len + 1]) chmax(dp[l - 1][l + len + 1][k], dp[l][l + len][k] + 2);
                else chmax(dp[l - 1][l + len + 1][k + 1], dp[l][l + len][k] + 2);
                chmax(dp[l - 1][l + len][k], dp[l][l + len][k]);
                chmax(dp[l][l + len + 1][k], dp[l][l + len][k]);
            }
        }
    }
    int ans = 0;
    for(int l = 0; l < S.length(); l++){
        for(int r = l; r < S.length(); r++){
            for(int k = 0; k <= K; k++){
                chmax(ans, dp[l][r][k]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}