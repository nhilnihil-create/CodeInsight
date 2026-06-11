#include <bits/stdc++.h>
using namespace std;
 
int main() {
    long long K, A, B;
    cin >> K >> A >> B;
    long long ret = 1; // number of biscuit
 
    if (
        B-A > 2 // 錬金したほうが得
        || K < A - 1 + 2// 錬金できるか　A枚のビスケット, -1 最初の一枚, +2 錬金に必要な回数
    ) {
        // A になるまでたたく
        K -= (A - 1);
        ret = A;
        
        // 回数限度まで錬金する
        int num = K / 2; // 錬金回数
        K -= num * 2; // 錬金後の残回数
        ret += num * (B - A);
 
        // 最後の調整
        ret += K;
    } else { // たたいた方が得
        ret += K;
    }
 
    cout << ret << endl;
    return 0;
}