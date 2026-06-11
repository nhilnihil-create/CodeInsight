#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;
    vector<long long> p(n);

    for(long long i = 0; i < n; i++){
        cin >> p[i];
    }

    vector<long long> dp(n+1, 0);

    long long maxv = 0;
    for(long long i = 0; i < n ;i++){
        long long t = p[i];
        dp[t] = dp[t-1] + 1;
    }

    for(long long i = 0; i <= n ;i++){
        maxv = max(maxv, dp[i]);
    }

    cout << n - maxv << endl;
    return 0;
}