#include <bits/stdc++.h>
using namespace std;
#define rep(i,n)for(int i=0;i<(n);i++)
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
using ll = long long;
using P = pair<int, int>;

const int MAX_N = 15;
const int MAX_W = 110000;

int dp[MAX_N][MAX_W];

int main(){
    int w; cin >> w;
    vector<int> weight;
    for(int i = 1; i <= w; i *= 6) weight.push_back(i);
    for(int i = 9; i <= w; i *= 9) weight.push_back(i);
    int n = (int)weight.size();
    for(int i = 0; i < MAX_N; ++i)for(int j = 0; j < MAX_W; ++j) dp[i][j] = 1 << 29;
    for(int i = 0; i <= n; ++i) dp[i][0] = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= w; j++){
            dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
            if(j >= weight[i]) dp[i+1][j] = min(dp[i+1][j], dp[i+1][j-weight[i]] + 1);
        }
    }
    cout << dp[n][w] << endl;
}