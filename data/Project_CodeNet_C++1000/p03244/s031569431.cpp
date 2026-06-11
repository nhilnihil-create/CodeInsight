// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    int n;
    vector<int> ki(100005,0), gu(100005,0);
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        if (i % 2 == 0) {
            gu[v]++;
        }
        else {
            ki[v]++;
        }
    }
    int ans = 0;
    int maxki = 0;
    int maxki2 = 0;
    int kiind = 0;
    int kiind2 = 0;
    int maxgu = 0;
    int maxgu2 = 0;
    int guind = 0;
    int guind2 = 0;
    for (int i = 1; i <= 100000; i++) {
        if (ki[i] >= maxki) {
            maxki2 = maxki;
            maxki = ki[i];
            kiind2 = kiind;
            kiind = i;
        }
        else if (ki[i] > maxki2) {
            maxki2 = ki[i];
        }

        if (gu[i] >= maxgu) {
            maxgu2 = maxgu;
            maxgu = gu[i];
            guind2 = guind;
            guind = i;
        }
        else if (gu[i] > maxgu2) {
            maxgu2 = gu[i];
        }
    }
    if (kiind == guind) {
        //if (maxki >= maxgu) {
        //    ans = (n / 2) - maxki + (n / 2) - maxgu2;
        //}
        //else {
        //    ans = n - maxgu - maxki2;
        //}
        ans = min(n - maxki - maxgu2, n - maxgu - maxki2);
    }
    else {
        ans = n - maxgu - maxki;
    }

    cout << ans << endl;
}

