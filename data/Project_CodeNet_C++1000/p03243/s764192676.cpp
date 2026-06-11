// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int main()
{
    int n;

    cin >> n;

    for (int i = n; i < 1000; i++) {
        int a = i % 10;
        int b = (i / 10) % 10;
        int c = i / 100;

        if (a == b && b == c) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}

