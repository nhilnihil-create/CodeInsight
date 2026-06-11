// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include <string>
#include<algorithm>
#include<vector>
#include<cmath>


using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    vector<int>x(n);

    int minx = 1000000000;

    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    for (int i = 0; i <= n - k; i++) {
        int a = min(abs(x[i]) + abs(x[i + k - 1] - x[i]), abs(x[i + k - 1]) + abs(x[i + k - 1] - x[i]));
        if (minx > a) {
            minx = a;
        }
    }

    cout << minx << endl;

    return 0;
}

