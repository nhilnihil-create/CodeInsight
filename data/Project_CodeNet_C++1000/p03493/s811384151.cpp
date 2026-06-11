#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ここにプログラムを追記
    string a;
    int cnt = 0;

    cin >> a;

    for (int i = 0; i < 3; i++)

        if (a[i] == '1')
        {
            cnt += 1;
        }

    cout << cnt << endl;
}
