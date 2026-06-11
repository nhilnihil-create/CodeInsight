// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long
const string K = "keyence";

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    string s;
    cin >> s;

    const int n = s.size();

    bool ans = s == K;

    // sのiからjまでの文字列を取り除いてキーエンス文字列か確認する
    for (int i = 0; i < n && !ans; i++) {
        for (int j = i; j < n - 1 && !ans; j++) {
            const string t = s.substr(0, i) + s.substr(j + 1);
            if (t == K) {
                ans = true;
            }
        }
    }

    cout << (ans ? "YES" : "NO") << endl;
}
