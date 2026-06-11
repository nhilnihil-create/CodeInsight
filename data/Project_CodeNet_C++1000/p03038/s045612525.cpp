// D.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
    int n, m;

    cin >> n >> m;
    vector<int>a(n), d;
    vector<pair<int,int>>p(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++) {
        int b, c;

        cin >> b >> c;

        p[i] = make_pair(c, b);

    }

    sort(p.begin(), p.end(), std::greater<pair<int,int>>());
    
    int key = 0;
    int i = 0;
    while (d.size() < n && key<m) {

        if (p[key].first <= a[i])break;
        if (p[key].second > 1) {
            if (p[key].first > a[i]) {
                d.push_back(p[key].first);
                p[key].second--;
                i++;
            }

        }
        else if (p[key].second==1){
            if (p[key].first > a[i]) {
                d.push_back(p[key].first);
                p[key].second--;
                i++;
            }
            key++;
        }
    }

    while (i < n) {
        d.push_back(a[i]);
        i++;
    }

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += d[i];
    }

    cout << ans << endl;
}

