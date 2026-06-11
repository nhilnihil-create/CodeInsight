#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 変数の宣言
    int a = 0;
    int b = 0;
    int x = 0;

    // 変数の入力を受け取る
    cin >> a;
    cin >> b;

    // あまりがあれば、xの小数点以下を切り上げる
    x = a + b;
    if (x % 2 != 0)
    {
        x = x / 2 + 1;
    }
    else
    {
        x = x / 2;
    }

    // 出力
    cout << x << endl;
}
