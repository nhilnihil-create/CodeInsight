#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const int INF = 10000;

int num[9] = {2, 5, 5, 4, 5, 6, 3, 7, 6};  // num[i] : iを作るのに必要なマッチの本数

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    rep(i, m) {
        cin >> a[i];
        a[i]--;  // a[i]を0-indexにする
    }
    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());  // aを降順ソート

    vector<int> dp(n+1, -INF);  // dp[i] : i本(iは1-index)のマッチを使って条件を満たすように整数を作るときの桁数の最大値

    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
        rep(j, m) {
            if(i >= num[a[j]]) {
                dp[i] = max(dp[i], dp[ i - num[a[j]] ] + 1);
            }
        }
    }

    int nokori = n;  // 残っているマッチの本数
    rep(i, dp[n]) {  // dp[n]桁作る
        rep(j, m) {  // a[j]が作れるか調べる
            if(nokori >= num[a[j]] && dp[ nokori - num[a[j]] ] == dp[nokori] - 1) {  // a[j]が作れる場合
                cout << a[j] + 1;  // 1-indexにしたa[j]を出力して
                nokori -= num[a[j]];  // 残り本数をnum[a[j]]本減らして
                break; // 次の桁に行く
            }
        }
    }

    cout << endl;
    return 0;
}