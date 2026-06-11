// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;
int main()
{
    int n;
    int max = 0;
    int p;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> p;

        if (max < p)max = p;
        ans += p;
    }

    ans -= max / 2;

    cout << ans << endl;
    return 0;
}

