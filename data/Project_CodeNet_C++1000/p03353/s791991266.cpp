#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main() {
    string s;
    cin >> s;
    int k;
    scanf("%d", &k);

    vector<string> vec;
    
    // 辞書順 K 番目の文字列の長さが K を超えることはない
    rep(i, s.size()) {
        for (int j = 1; j <= k; j++)
        {
            string temp = s.substr(i, j); //i番目以降の文字列をj文字だけ取り出す。iは0スタート、jは1スタート。
            vec.push_back(temp);
        }
    }

    // 昇順
    sort(vec.begin(), vec.end());

    // 重複削除
    vec.erase(unique(vec.begin(), vec.end()), vec.end());

    cout << vec[k - 1] << endl;
    return 0;
}