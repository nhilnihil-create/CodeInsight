// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int main()
{
    int a, b;

    cin >> a >> b;

    if (a % 2 == 0 || b % 2 == 0) {
        cout << "No" << endl;
        return 0;
    }

    cout << "Yes" << endl;

    return 0;
}

