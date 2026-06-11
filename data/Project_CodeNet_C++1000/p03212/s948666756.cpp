// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>

using namespace std;
long long n;
int cnt = 0;

void check(long long x) {
    bool ok[3] = { false,false,false };

    if (x > n)return;
    int amari;
    while (x > 0) {
        amari = x % 10;
        if (amari == 3 ) {
            ok[0] = true;
        }
        else if (amari == 5) {
            ok[1] = true;
        }
        else if (amari == 7) {
            ok[2] = true;
        }

        x /= 10;
    }

    if (ok[0] == true && ok[1] == true && ok[2] == true) {
        cnt++;
        return;
    }
    else {
        return;
    }
}

void dfs(long long x) {
    check(x);
    if (x <= 1000000000) {
        dfs(10 * x + 3);
        dfs(10 * x + 5);
        dfs(10 * x + 7);
    }
}

int main()
{
 

    cin >> n;

    dfs(0);

    cout << cnt << endl;
}

