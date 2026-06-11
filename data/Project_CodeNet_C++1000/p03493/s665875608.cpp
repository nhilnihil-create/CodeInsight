#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 0;
    int b = 0;
    int c = 0;
    int s = 0;

    // 入力
    cin >> s;

    // 100の位
    a = s / 100;

    // 10の位
    b = (s / 10) % 2;

    // 1の位
    c = s % 2;

    // 出力
    cout << a + b + c << endl;
}
