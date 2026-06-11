#include <bits/stdc++.h>
#include <iostream>
#include<math.h>
using namespace std;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
int main()
{
    int64_t N;
    cin >> N;
    int64_t INF = INT64_MAX;
    vector<int64_t>dp(N+1, INF);
    dp[0] = 0;
    dp[1] = 1;
    int64_t j = 1;
    vector<int64_t> six_pow_vec;
    while (pow(6, j) <= N) {
        six_pow_vec.emplace_back(pow(6, j));;
        j++;
    }

    j = 1;
    vector<int64_t> nine_pow_vec;
    while (pow(9, j) <= N) {
        nine_pow_vec.emplace_back(pow(9, j));
        j++;
    }

    for (int64_t i=2;i<=N;i++) {
        chmin(dp[i], dp[i-1] + 1);
        for (int64_t j=0; j<six_pow_vec.size(); j++) {
            if (0 > i - six_pow_vec[j]) {
                break;
            }

            chmin(dp[i], dp[i-six_pow_vec[j]] + 1);
        }

        for (int64_t j=0; j<nine_pow_vec.size(); j++) {
            if (0 > i - nine_pow_vec[j]) {
                break;
            }

            chmin(dp[i], dp[i-nine_pow_vec[j]] + 1);
        }
    }

    cout << dp[N] << endl;
    return 0;
}