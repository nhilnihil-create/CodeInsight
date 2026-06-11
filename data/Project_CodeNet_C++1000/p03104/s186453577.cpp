#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B;

// 0 ~ x までの xor を求める
// 周期2を利用するパターン
ll f(ll x) {
    ll tmp = (x + 1) / 2;
    tmp %= 2;
    // x が偶数の時、はみ出る (0-indexed)
    if (x % 2 == 0) {
        tmp ^= x;
    } 
    return tmp;
}

int main() {
    cin >> A >> B;
    // cout << f(A - 1) << endl;
    // cout << f(B) << endl;

    ll ans = f(B) ^ f(A - 1);
    cout << ans << endl;
}