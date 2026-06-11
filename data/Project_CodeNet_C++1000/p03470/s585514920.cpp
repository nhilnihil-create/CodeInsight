#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 入力を受け取りながらバケットを作る
    int N;
    cin >> N;
    vector<int> num(110, 0); // 全体を 0 で初期化
    for (int i = 0; i < N; ++i) {
        int d;
        cin >> d;
        num[d]++;
    }

    // 数える
    int result = 0;
    for (int i = 0; i < 110; ++i) {
        // num[i] != 0 (0 以外の値は true) ならばインクリメント
        if (num[i]) ++result;
    }
    cout << result << endl;
}