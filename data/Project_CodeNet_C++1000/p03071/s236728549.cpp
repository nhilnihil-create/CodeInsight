// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    if (a > b) {
        cout << a + a - 1 << endl;
    }
    else if (a == b) {
        cout << a + b << endl;
    }
    else {
        cout << b + b - 1 << endl;
        
    }
    return 0;
}

