#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

long lucas_dp[100];

long lucas(long n) {
    if(lucas_dp[n] != 0)
        return lucas_dp[n];

    long l = lucas(n - 1) + lucas(n - 2);
    lucas_dp[n]= l;
    return l;
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long n;
    cin >> n;
    // long lucas[100];
    lucas_dp[0] = 2;
    lucas_dp[1] = 1;
    // for(int i =2;i<=n;i++){
        // lucas[i] = lucas[i-1]+lucas[i-2];
    // }
    cout<<lucas(n)<<endl;
}