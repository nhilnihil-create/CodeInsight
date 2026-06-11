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


    vector<pair<long long , long long>>v;
    for (int i = 0; i < n; i++) {
        long long a, b;
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
    sort(v.begin(), v.end());
    long long ans = 0;
    int i = 0;
    while (m > 0) {
        if (m > v[i].second) {
            ans += v[i].first * v[i].second;
            m -= v[i].second;
        }
        else {
            ans += v[i].first * m;
            m = 0;

        }
        i++;
    }

    cout << ans << endl;
    return 0;
}

