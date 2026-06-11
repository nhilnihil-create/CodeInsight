#define rep(i, n) for (int i = 0; i < (n); i++)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int MOD = 1000000007;

int main() {
    int N, K;
    cin >> N >> K;

    int number = 1;
    rep(i, N) { // 小さい方を採択する
        int mulNumber = number * 2;
        int addNumber = number + K;
        number = min(mulNumber, addNumber);
    }

    cout << number << endl;

    return 0;
}