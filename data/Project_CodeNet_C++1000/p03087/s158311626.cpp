// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>

using namespace std;

int main()
{
    int wa[100005];
    int n, q;

    string s;
    cin >> n >> q;

    cin >> s;
    wa[0] = 0;
    for (int i = 0; i < s.size()-1; i++) {
        if (s[i] == 'A' && s[i + 1] == 'C') {
            wa[i + 1] = wa[i] + 1;
        }
        else {
            wa[i + 1] = wa[i];
        }
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;

        cout << wa[r - 1] - wa[l - 1] << endl;
    }

    return 0;
}

