#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S;
    cin >> S;
    int N = S.size();

    // dp[i][j] : S[i-1]まで使って"ABC"のj文字目まで使った場合の決め方の数
    vector<vector<ll>> dp(N+1, vector<ll>(4));
    dp[0][0] = 1;

    for(int i = 1; i <= N; i++){
        for(int j = 3; j >= 0; --j){
            // transition
            // S[i-1]を使わない場合
            // '?'->3通り, 'A','B','C'-> 1通り
            dp[i][j] = dp[i-1][j] * (S[i-1] == '?' ? 3LL : 1LL);
            // S[i-1]を使う場合
            // j-1 -> j への遷移は
            // S[i-1] = '?' or "ABC"[j-1] であれば良い
            if(0 < j && (S[i-1] == '?' || S[i-1] == "ABC"[j-1])){
                dp[i][j] += dp[i-1][j-1];
            }
            dp[i][j] %= mod;
        }
    }
    cout << dp[N][3] << endl;
}
