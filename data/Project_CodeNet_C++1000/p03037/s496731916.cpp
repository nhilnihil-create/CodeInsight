// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    int l, r;
    int judge[100005] ;
    
    cin >> n >> m;
    for (int i = 0; i <= n; i++) {
        judge[i] = 1;
    }

    for (int i = 0; i < m; i++) {
        cin >> l >> r;

        l = l - 1;
        while (judge[l]&& 0<l) {
            judge[l] = 0;
            l--;
        }
        r = r + 1;

        while (judge[r] && r <= n) {
            judge[r] = 0;
            r++;
        }


    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (judge[i] == 1)cnt++;
    }
    cout << cnt << endl;

    
}

