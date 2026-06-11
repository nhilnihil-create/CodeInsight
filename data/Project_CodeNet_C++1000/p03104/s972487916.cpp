#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const ll INF = 1LL << 60;

ll A, B;

// // 0 ~ x までの xor を求める
// // 周期2を利用するパターン
// ll f(ll x) {
//     ll tmp = (x + 1) / 2;
//     tmp %= 2;
//     // x が偶数の時、はみ出る (0-indexed)
//     if (x % 2 == 0) {
//         tmp ^= x;
//     } 
//     return tmp;
// }

// 0 ~ x までの xor を求める
ll f(ll x) {
    ll ans = 0;

    // 0-indexed なのでたす
    x++;

    for (int i = 0; i < 41; i++) {
        // 0桁目 -> 周期2
        // 1桁目 -> 周期4
        // 2桁目 -> 周期8
        ll loop_cnt = (1LL << (i + 1));

        // 1は周期の半分ずつ出てくる
        ll cnt = (x / loop_cnt) * (loop_cnt / 2);

        // はみ出た分カウントとる
        // 周期の前半は 0 で埋められている
        cnt += max(0LL, (x % loop_cnt) - (loop_cnt / 2));

        // その桁の1の数が奇数なら、足し算 (xor の結果が1になる)
        if (cnt % 2 == 1) {
            ans += (1LL << i);
        }
    }

    return ans;
}

int main() {
    cin >> A >> B;
    // cout << f(A - 1) << endl;
    // cout << f(B) << endl;

    // xor のたし算、引き算は、そのまま xor で ok
    ll ans = f(B) ^ f(A - 1);
    cout << ans << endl;
}