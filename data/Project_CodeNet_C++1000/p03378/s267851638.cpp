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

signed main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    int cost0 = 0, costn = 0;
    for (auto &&i : a) {
        if (i >= x)
            costn++;
        else
            cost0++;
    }

    const int ans = min(cost0, costn);
    cout << ans << endl;
}

// 左か右に移動し続けるのが最適
// マス0とマスXの間の料金所の数が、左に移動し続けてマス0に到達してゴールするコスト
// マスNマスXの間の料金所の数が、右に移動し続けてマスNに到達してゴールするコスト
// この2つの小さい方が答え
