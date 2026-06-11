// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;

    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < s.size(); i++) {
        if (i%2==0) {
            if (s[i] != '0')cnt1++;
        }
        else {
            if (s[i] != '1')cnt1++;
        }
    }

    cnt2 = s.size() - cnt1;
    if (cnt1 < cnt2) {
        cout << cnt1<<endl;
    }
    else {
        cout << cnt2 << endl;
    }
    return 0;
}

