#include <iostream>

using namespace std;
typedef long long ll;
ll dp[5001][5001];
ll A, B;
int N;
int p[5001];
const ll INF = 1e+18;

int main(){
    cin >> N >> A >> B;
    for(int i = 0; i < N; i++) cin >> p[i];
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= N; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j <= N; j++){
            if(dp[i][j] == INF) continue;
            if(j < p[i]){
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+A);
                dp[i+1][p[i]] = min(dp[i+1][p[i]], dp[i][j]);
            }else{
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]+B);
            }
        }
    }
    ll ans = INF;
    for(int i = 0; i <= N; i++) ans = min(ans, dp[N][i]);
    cout << ans << endl;
}