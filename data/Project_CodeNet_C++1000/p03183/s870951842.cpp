#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <set>
#include <map>

using namespace std;

typedef pair<int, int> P;

P p[1000];
int w[1000], s[1000], v[1000];
long dp[1001][20001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    int N;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> w[i] >> s[i] >> v[i];
        p[i] = P(s[i]+w[i], i);
    }
    sort(p, p+N);
    long ans = 0;
    for(int j = 1; j <= 20000; j++){
        dp[0][j] = -100000000000000;
    }
    for(int i = 0; i < N; i++){
        int idx = p[i].second;
        //cout << s[idx] << ' ' << w[idx] << endl;
        for(int j = 0; j <= 20000; j++){
            dp[i+1][j] = dp[i][j];
        }
        for(int j = 0; j <= s[idx]; j++){
            dp[i+1][j+w[idx]] = max(dp[i+1][j+w[idx]], dp[i][j]+v[idx]);
            ans = max(ans, dp[i+1][j+w[idx]]);
        }
    }
    cout << ans << endl;
}