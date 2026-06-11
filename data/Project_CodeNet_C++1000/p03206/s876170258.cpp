// A.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;
int main()
{
    int n;

    cin >> n;

    if (n == 22) {
        cout << "Christmas Eve Eve Eve" << endl;
    }
    else if (n == 23) {
        cout << "Christmas Eve Eve" << endl;
    }
    else if (n == 24) {
        cout << "Christmas Eve" << endl;
    }
    else {
        cout << "Christmas" << endl;
    }
    return 0;
}

