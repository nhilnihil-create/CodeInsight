#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <functional>
#include <iomanip>
#include <cstring>

using namespace std;

#define DIGITS 50

template<class T> inline void chmax(T& a, const T& b) { if (a < b) { a = b; } }

long long dp[DIGITS+1][2];

int main() {
    int n;
    long long k;
    cin>>n>>k;
    vector<long long> a;
    long long x;
    for (int i=0;i<n;++i){
        cin>>x;
        a.push_back(x);
    }
    memset(dp, -1, sizeof(dp));
    dp[0][0]=0;
    for (int i = 0; i < DIGITS; ++i) {
        long long mask = 1ll << (DIGITS-i-1);
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (mask & a[j])
                ++cnt;
        }
        if (dp[i][1] != -1) {
            chmax(dp[i+1][1], dp[i][1] + mask*max(cnt,n-cnt));
        }
        if (dp[i][0] != -1) {
            if (k & mask) {
                chmax(dp[i+1][1], dp[i][0] + mask*cnt);
            }
            else chmax(dp[i+1][0], dp[i][0]);
        }
        if (dp[i][0] != -1) {
            if (k & mask) chmax(dp[i+1][0], dp[i][0] + mask*(n-cnt));
            else chmax(dp[i+1][0], dp[i][0] + mask*cnt);
        }
    }
    cout << max(dp[DIGITS][0], dp[DIGITS][1]);
}