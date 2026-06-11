#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;

long lucas(long n) {
    if(n == 0)
        return 2;
    if(n == 1)
        return 1;

    return lucas(n - 1) + lucas(n - 2);
}

int main() {
    // 制約見て！！！デカかったらlong longにすること！
    long n;
    cin >> n;
    long lucas[100];
    lucas[0]=2;
    lucas[1] =1;
    for(int i = 2; i <= n; i++) {
        lucas[i] = lucas[i - 1] + lucas[i - 2];
    }
    cout << lucas[n] << endl;
}