#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, m, n) for(int i = (int)(m); i < (int)(n); ++i)


int main()
{
    int N;
    cin >> N;
    vector<int> w(N), s(N), v(N);
    REP(i, N) cin >> w[i] >> s[i] >> v[i];
        
    vector<int> ord;
    REP(i, N) ord.push_back(i);
    sort(ord.begin(), ord.end(), [&](int i, int j){ return min(s[i], s[j]-w[i]) > min(s[j], s[i]-w[j]);});

    // dp[i][j]: 最適な方からi番目まで決めたとき、重さが j になる価値の総和の最大値
    vector<vector<long long>> dp(N+1, vector<long long>(3e+4+1));
    REP(i, N){
        int idx = ord[i];
        REP(j, 2e+4+1){
            dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
            if(s[idx] >= j) dp[i+1][j+w[idx]] = max(dp[i+1][j+w[idx]], dp[i][j]+v[idx]);
        }
    }
    cout << *max_element(dp[N].begin(), dp[N].end()) << endl;

    return 0;
}