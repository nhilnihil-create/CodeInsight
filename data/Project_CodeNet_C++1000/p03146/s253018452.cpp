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

constexpr int f(int n) {
    if (n % 2) return 3 * n + 1;
    return n / 2;
}

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int s;
    cin >> s;

    set<int> as;

    int ai = s;
    as.insert(ai);

    for (int i = 2;; i++) {
        ai = f(ai);

        if (as.count(ai) > 0) {
            cout << i << endl;
            return 0;
        }

        as.insert(ai);
    }
}

// aiをa1から計算
// a1からaiまでをsetに記録
// もしaiが既出ならばiを出力して終了
