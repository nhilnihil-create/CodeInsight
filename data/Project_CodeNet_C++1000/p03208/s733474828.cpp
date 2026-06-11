// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int k, n;

    cin >> n >> k;

    vector<int>v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int min = 1000000000;

    for (int i = 0; i < n-k+1; i++) {
        if (v[i + k - 1] - v[i] < min)min = v[i + k - 1] - v[i];
    }

    cout << min << endl;

    return 0;
}

