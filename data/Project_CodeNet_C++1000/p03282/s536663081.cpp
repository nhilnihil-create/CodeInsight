// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
using namespace std;
int main()
{
    int k;
    string s;

    cin >> s;
    cin >> k;
    int key;
    k--;
    for (int i = 0; i < 100; i++) {
        if (s[i] != '1') {
            key = i;
            break;
        }
    }

    if (k < key) {
        cout << '1' << endl;
    }
    else {
        cout << s[key] << endl;
    }

    return 0;
}
