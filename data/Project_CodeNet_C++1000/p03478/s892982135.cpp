#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// 整数 n の各桁の和を求める関数
int calc_sum_digits(int n) {
    stringstream ss;
    ss << n;
    string str = ss.str();
    int res = 0;
    for (char c : str) res += c - '0';
    return res;
}

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int result = 0; // 答えを格納する変数
    for (int n = 1; n <= N; ++n) {
        // 整数 n の「各桁の和」を求める
        int sum = calc_sum_digits(n);

        // 「各桁の和」が A 以上 B 以下である場合は答えに加算
        if (sum >= A && sum <= B) result += n;
    }
    cout << result << endl;
}