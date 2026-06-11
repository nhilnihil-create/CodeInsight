// B.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//


#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


bool compare(pair<string, int> a, pair<string, int >b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }

    if (a.second != b.second) {
        return a.second > b.second;
    }
    else {
        return true;
    }
}

int main()
{
    pair<string, int> P;
    vector < pair<string, int>> v,v2;
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> P.first >> P.second;

        v.push_back(P);
        v2.push_back(P);
    }
    sort(v.begin(), v.end(),compare);

    for (int i = 0; i < n; i++) {
        //cout << v[i].first << " " << v[i].second << endl;
        for (int j = 0; j < n; j++) {
            if (v[i].first == v2[j].first) {
                if (v[i].second == v2[j].second) {
                    cout << j + 1 << endl;
                }
            }
        }
    }
    return 0;
}

