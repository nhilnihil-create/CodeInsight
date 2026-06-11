#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <bitset>
#include <unordered_map>

using ll = long long;

using namespace std;

using bs = bitset<26>;
#define INF 200010

#include <map>
#include <set>
// vecのなかの全要素について座標圧縮を行い、元座標->圧縮後座標というmapを作る
// O(NlogN) 座圧後のサイズを返す
// org: もともとの各iに対する座標 値渡しなので破壊しません
// zip: 圧縮
// unzip: 復元
template <typename T>
int compress(vector<T> org, map<T, int> &zip, vector<T> &unzip) {
    sort(org.begin(), org.end()); 
    org.erase(unique(org.begin(), org.end()), org.end()); // vecの各要素を小さい順に重複を無くして並べたもの
    int i = 0;
    for (auto &oi : org) {
        zip[oi] = i;
        unzip.push_back(oi);
        i++;
    }
    return i;
}

int main() {
    string s;
    cin >> s;
    int len = s.size();
    vector<bs> rui(1, 0);
    for (int i=0; i<len; i++) {
        rui.push_back(rui.back());
        rui.back().flip(s[i] - 'a');
    }
    unordered_map<bs, int> dp;
    dp[0] = 0;
    for (int i=0; i<=len; i++) {
        for (int j=0; j<=26; j++) {
            bs from = rui[i];
            if (j > 0) from = from.flip(j-1);
            if (!dp.count(rui[i])) dp[rui[i]] = INF;
            if (!dp.count(from)) dp[from] = INF;
            dp[rui[i]] = min(dp[rui[i]], dp[from] + 1);
        }
    }
    cout << max(dp[rui[len]], 1) << '\n';
    return 0;
}