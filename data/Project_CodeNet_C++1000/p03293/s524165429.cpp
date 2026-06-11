// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>

using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;

    for (int i = 0; i < s.length(); i++) {
        s = s[s.length() - 1] + s.substr(0,s.length() - 1);

        if (s == t) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

    
}