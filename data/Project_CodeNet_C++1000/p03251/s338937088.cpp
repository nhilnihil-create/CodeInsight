// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
using namespace std;
int main()
{
    int n, m, x, y;

    cin >> n >> m >> x >> y;

    int xmax = x;
    int ymin = y;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (xmax < a) {
            xmax = a;
        }
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        if (ymin > b) {
            ymin = b;
        }
    }

    if (xmax < ymin) {
        cout << "No War" << endl;
    }
    else {
        cout << "War" << endl;
    }
}

