#include <bits/stdc++.h>
using namespace std;

int64_t calc_Lucas(vector<int64_t> &lucas, int N, int i) {
    // 停止
    if (i == N) {
        return lucas.at(i);
    }

    // 処理
    int64_t r;
    r = lucas.at(i) + lucas.at(i-1);
    lucas.push_back(r);

    // 再帰
    return calc_Lucas(lucas, N, i + 1);
}

int main() {
    int N;
    cin >> N;

    // 初期値の設定
    vector<int64_t> lucas(2);
    lucas.at(0) = 2;
    lucas.at(1) = 1;

    cout << calc_Lucas(lucas, N, 1) << endl;
}
