#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long> a;

    a.push_back(1);

    long long x = 6;
    for(long long i = 0; i < 6; i++){
        a.push_back(x);
        x *= 6;
    }

    long long y = 9;
    for(long long i = 0; i < 9; i++){
        a.push_back(y);
        y *= 9;
    }

    vector<long long> dp(100001, 1e9);
    dp[0] = 0;

    for(long long i = 0; i <= 100000; i++){
        for(long long j = 0; j < a.size(); j++){
            if(i >= a[j]) dp[i] = min(dp[i], dp[i-a[j]]+1);
        }
    }

    cout << dp[n] << endl;
    return 0;
}