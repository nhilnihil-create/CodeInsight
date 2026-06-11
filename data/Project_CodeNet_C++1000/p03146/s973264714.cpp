// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;


int state[1000000];
int main()
{
    int s;
    
    cin >> s;
    int ans = 1;
    while (1) {
        state[s]++;
        if (state[s] == 2)break;
        if (s % 2 == 0)s = s / 2;
        else s = 3 * s + 1;
        ans++;
    }
    cout << ans << endl;

    return 0;
}

