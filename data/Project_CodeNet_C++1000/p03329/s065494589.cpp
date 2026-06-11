#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int dp[1000000];
int INF = 1001001001;

int main() {
    int N; cin >> N;
    rep(i, N+1){
        dp[i] = i;
    }
    for (int i = 0; i < N; i++){
        int now6 = 6;
        while(now6 <= N){
            dp[i+now6] = min(dp[i+now6], dp[i] + 1);
            now6 *= 6;
        }
        int now9 = 9;
        while(now9 <= N){
            dp[i+now9] = min(dp[i+now9], dp[i] + 1);
            now9 *= 9;
        }
    }

    cout << dp[N] << endl;

    return 0;
}