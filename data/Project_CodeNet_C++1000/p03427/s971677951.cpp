#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
int64_t INF = 1000000007;
// int64_t INF = 9223372036854775807;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    string s;
    cin >> s;
    // 頭の一桁を1つ落とすのが得策
    // もしくは最初から全てが9の場合
    int64_t res = 0;
    rep(i,s.size()){
        res += s.at(i)-'0';
    }
    int64_t logicalMax = 9*(s.size()-1)+(s.at(0)-'0'-1);
    res = max(res, logicalMax);
    cout << res << endl;
}