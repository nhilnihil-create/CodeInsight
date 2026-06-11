#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N;
    cin >> N;

    double number = N;
    rep(i, N) {  // 最大でN回繰り返す
        double numberSqrt = sqrt(number);
        if (floor(numberSqrt) * floor(numberSqrt) == number) break;
        number--;
    }

    cout << std::fixed << std::setprecision(0) << number << endl;

    return 0;
}