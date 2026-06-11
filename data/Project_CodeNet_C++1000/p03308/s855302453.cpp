// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    int n;

    cin >> n;
    int a[105];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int m = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            m = max(m, abs(a[i] - a[j]));
        }
    }

    cout << m << endl;

    return 0;
}
