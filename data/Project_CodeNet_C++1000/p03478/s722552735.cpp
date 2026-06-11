#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int sumDigits(int number) {
    int sum = 0;
    while (number > 0) {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (A <= sumDigits(i) && sumDigits(i) <= B) {
            sum += i;
        }
    }

    cout << sum << endl;

    return 0;
}
