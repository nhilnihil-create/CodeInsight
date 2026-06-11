// C.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
    
    int n, m;

    cin >> n >> m;
    vector<int> point(m);
    vector<int >kan(m-1);
    for (int i = 0; i < m; i++) {
        cin >> point[i];
    }

    sort(point.begin(), point.end());
    int sum = 0;
    for (int i = 0; i < m - 1; i++) {
        kan[i] = point[i + 1] - point[i];
        sum += kan[i];
    }
    //cout << sum << endl;
    sort(kan.begin(),kan.end());
    for (int i = 0; i < n-1; i++) {
        if (m - 2 - i < 0)break;
        sum -= kan[m - 2 - i];
    }
    //for (int i = 0; i < m ; i++) {
    //    cout << kan[i] << endl;
    //}
    cout << sum << endl;

    return 0;



}

