#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, used, reversed;
    int count = 0;
    cin >> A >> B;

    // ここにプログラムを追記
    // 入力される符号と値

    // A以上B以下の整数の繰り返し処理
    while (A <= B)
    {
        reversed = 0;
        used = A;
        //
        while (used > 0)
        {
            reversed = used % 10 + reversed * 10;
            used = used / 10;
        }

        // 回文数の場合
        if (A == reversed)
        {
            count++;
        }
        A++;
    }
    cout << count;
}
