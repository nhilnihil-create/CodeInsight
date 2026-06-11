/* coordinate_compress_2D.cpp
    2Dの座標圧縮を行う

    verified: [AOJ] DSL_4_A Union of Rectangles
        http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A&lang=ja
*/

#include <bits/stdc++.h>
using namespace std;

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d <= 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc1 = C1[i] + d;
            T tc2 = C2[i] + d;
            vals.push_back(tc1);
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}

using ll = long long;
int main() {
    int N, x;
    cin >> N >> x;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a.at(i);
    }
    sort(a.begin(), a.end());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (x >= a[i]) {
            x -= a[i];
            ans++;
        } else {
            x = 0;
            break;
        }
    }
    if (x > 0) {
        ans--;
    }
    cout << ans << endl;
}
