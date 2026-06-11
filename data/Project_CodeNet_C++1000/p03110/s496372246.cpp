// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<string>
using namespace std;
int main()
{
    double ans=0;

    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        double x;
        string s;

        cin >> x >> s;

        if (s == "JPY") {
            ans += x;
        }
        else {
            ans += 380000 * x;
        }
    }
    printf("%.5f", ans);
    return 0;
}

