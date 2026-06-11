// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int a[5];

    for (int i = 0; i < 5; i++) {
        cin >> a[i];
    }

    int sa[5];
    int maxi;
    int max = -1;
    int ans = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 1; j <= 13; j++) {
            if (j * 10 >= a[i]) {
                sa[i] = j * 10 - a[i];
                break;
            }
        }
    }

    for (int i = 0; i < 5; i++) {
        if (max < sa[i]) {
            max = sa[i];
            maxi = i;
        }
    }
    for (int i = 0; i < 5; i++) {
        if (i != maxi) {
            ans += sa[i] + a[i];
        }
    }
    ans += a[maxi];

    
    cout << ans << endl;

    return 0;
}