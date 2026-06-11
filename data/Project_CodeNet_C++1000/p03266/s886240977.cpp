#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
typedef long long Int;


int main() {
    Int N, K;
    cin >> N >> K;

    Int ans = 0;
    ans += (N/K) * (N/K) * (N/K);

    if (K % 2 == 0) {
        Int k, x;
        k = K / 2;
        x = (N / k) - (N / K);
        ans += x * x * x;
    }

    cout << ans << endl;
}