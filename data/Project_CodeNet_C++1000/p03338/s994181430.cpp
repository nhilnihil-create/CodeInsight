// う　し　た　ぷ　に　き　あ　く　ん　笑
#include <algorithm>
#include <array>
#include <bitset>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>
using namespace std;
#define int long long

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    string s;
    cin >> s;

    int ans = 0;

    // 全探索する。Sを切断する位置を全通り試して、この問題のスコアを数える。

    // Sを切断する位置。Yはs[i],...,s[n-1]
    for (int i = 0; i < n; i++) {
        bitset<'z' - 'a' + 1> f, b;
        for (int j = 0; j < n; j++) {
            if (j < i)
                f.set(s[j] - 'a');
            else
                b.set(s[j] - 'a');
        }
        f &= b;
        const int nowans = f.count();
        ans = max(nowans, ans);
    }

    cout << ans << endl;
}
