#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef pair<int,int> P;
int INF = 1e9+7;
int mod = 1e9+7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cnt[12] = {1, 6, 9, 36, 81, 216, 729, 1296, 6561, 7776, 46656, 59049};
int dp[100005];
signed main() {
    int N;
    cin >> N;
    for(int i = 0; i <= 100000; i++) {
        dp[i] = INF;
    }
    dp[0] = 0;
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 12; j++) {
            if(i-cnt[j] >= 0) {
                dp[i] = min(dp[i],dp[i-cnt[j]]+1);
            }
        }
    }
    cout << dp[N] << endl;
}

