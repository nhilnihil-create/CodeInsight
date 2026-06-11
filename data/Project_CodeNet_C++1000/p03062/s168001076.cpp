// 7/3
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;

int main() {
    int N;
    cin >> N;
    vector<int> A(N);
    rep(i, N) cin >> A[i];

    ll res = 0;

    // 以下の解法は誤り。
    // rep(i, N-1) {
    //     if (A[i] > 0) {
    //         res += A[i];
    //     }
    //     else {
    //         ll now = A[i] + A[i + 1];
    //         if (now <= 0) {
    //             // ひっくり返す
    //             res -= A[i];
    //             A[i+1] *= -1;
    //         } else {
    //             // ひっくり返さない
    //             res += A[i];
    //         }
    //     }
    // }
    // res += A[N-1];

    // 解法②
    // 0があったら、それまでの数字は全てプラスにできる。
    // 0がなく末端がきたら、それまでの数字の中で一番絶対値が小さな数をマイナスにしておけば良い。

    // 改め、0があったら、全ての数字をプラスにできる。
    // 0がなければ、どれか絶対値が一番小さい１個をマイナスにする。
    // ll res = 0;
    // int mn = INT_MAX;
    // rep(i, N-1) {
    //     if (A[i+1] == 0) {
    //         mn = INT_MAX;
    //     }
    // }

    // ll res = 0;
    int mn = INT_MAX;
    int minus = 0;
    bool zero = false;

    rep(i, N) {
        res += abs(A[i]);
        mn = min(mn, abs(A[i]));
        if (A[i] == 0) zero = true;
        if (A[i] < 0) minus++;
    }

    if (zero) cout << res << endl;
    else if (minus % 2 == 0) cout << res << endl;
    else cout << res - 2 * mn << endl;
}