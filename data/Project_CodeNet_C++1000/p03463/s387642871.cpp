// 相手の動けるマスを減らすのが最適そう？
// 二人とも相手の方に近づいて、
// 動いて、相手と隣り合った時、動いた人が勝ちそう
// 引き分けになる場合がわからない、、、
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;
    bool turn = true;
    while (abs(A - B) > 1) {
        if (turn) {
            if (A < B)
                ++A;
            else
                --A;
        } else {
            if (A < B)
                --B;
            else
                ++B;
        }
        turn = !turn;
    }

    turn = !turn;  // 直前に動いた人が誰か調べる。
    if (turn)
        cout << "Alice" << endl;
    else
        cout << "Borys" << endl;

    return 0;
}