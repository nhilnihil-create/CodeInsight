// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;

int main()
{
    char a;

    cin >> a;

    if (a == 'A') {
        cout << 'T' << endl;
    }
    else if (a == 'C') {
        cout << 'G' << endl;

    }
    else if (a == 'G') {
        cout << 'C' << endl;

    }
    else {
        cout << 'A' << endl;


    }
    return 0;
}
