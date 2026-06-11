// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<cstdio>

using namespace std;

int main()
{
    int n, k;

    cin >> n >> k;

    double sum = 0;
    double kaku = (double)1 / n;

    for (int i = 0; i < n; i++) {
        double kake = 1;
        int cnt = 0;
        int me = i + 1;
        while (me < k) {

            kake *= 0.500;
            cnt++;

            me *= 2;
        }

        sum += kaku * kake;
    }

    printf("%.10f", sum);

    return 0;
}

