#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int A, B, C, K;
    cin >> A >> B >> C >> K;

    int maxValue = max(A, B);
    maxValue = max(maxValue, C);

    int leftSum = A + B + C - maxValue;

    int sum = maxValue;
    rep(i, K) {
        sum = sum * 2;
    }

    int ans = leftSum + sum;

    cout << ans << endl;

    return 0;
}
