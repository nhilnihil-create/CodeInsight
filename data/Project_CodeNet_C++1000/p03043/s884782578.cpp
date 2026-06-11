#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
using namespace std;

/*
 * kを超えるまで表が出続ける確率を計算
 */
double calc_coin_p(int k, int base) {
    // 振る回数
    int count = 0;
    // 確率
    double p = 1;

    // k以上になるまで振り続け、点数を倍にする
    while(base <= k - 1) {
        count++;   // 振る
        base *= 2; // 点数が倍
        p /= 2;    // 確率はさらに半分
    }
    return p;
}

int main() {
    int n, k;
    cin >> n >> k;
    double p = 0;

    double total = 0;
    for(int i = 1; i <= n; ++i) {
        total += calc_coin_p(k, i) / n;
    }

    cout << fixed << setprecision(15) << total << endl;
}