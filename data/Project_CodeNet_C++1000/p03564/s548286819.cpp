#include<bits/stdc++.h>
using namespace std;
// マクロ
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
// 型エイリアス
using ll = long long;
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vvs = vector<vs>;

int main() {
    int n, k;
    cin >> n >> k;
    int ans = 1;
    for(int i = 0; i < n; i++) {
        ans = min(2 * ans, ans + k);
    }
    cout << ans << endl;
}