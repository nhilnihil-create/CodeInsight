// 各iビット目について、
// 集合{Ai}のうちiビット目が立っている数がCiとすると、
// Xのiビット目を0にしたとき、fの値の寄与はCi*2^iになり、
// Xのiビット目を1にしたとき、fの値の寄与は(N - Ci)*2^iになる。
// なので、Xの各ビットについて、1か0のどちらにしたらfの値が大きくなるか調べ、
// それを答えにすればよい。。。
// 、、、が、X <= Kという制約があるため、これを満たしつつ最大となる数を探す。
// 詳しくはeditorial参照のこと
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    long long K;
    cin >> N >> K;
    long long res = 0;
    vector<long long> keta(60, 0);
    for (int i = 0; i < N; ++i) {
        long long A;
        cin >> A;
        res += A;
        for (int j = 0; j < 60; ++j) {
            if ((A >> j) & 1LL) ++keta[j];
        }
    }
    for (int mask = 0; mask < 60; ++mask) {
        if (((K >> mask) & 1LL) == 0) continue;  // Xi < Kiを満たせない場合を無視
        long long tmp = 0;
        //long long k_tmp = 0;  // デバッグ用
        for (int i = 0; i < mask; ++i) {
            tmp += max(N - keta[i], keta[i]) * (1LL << i);
            //if (keta[i] <= N - keta[i]) k_tmp += (1LL << i);
        }
        // maskビット目はかならず0にする。
        tmp += keta[mask] * (1LL << mask);  // この文を書いてなくてずっとバグってた
        for (int i = mask + 1; i < 60; ++i) {
            if ((K >> i) & 1LL) {
                tmp += (N - keta[i]) * (1LL << i);
                //k_tmp += (1LL << i);
            } else {
                tmp += keta[i] * (1LL << i);
            }
        }

        /*
        if (true) {
            cout << "mask: " << mask << " k_tmp: " << k_tmp << " K:" << K << " tmp: " << tmp << endl;
        }
        */

        //assert(k_tmp <= K);
        res = max(res, tmp);
    }
    // X == Kの場合について調べてなかったので、以下で調べる
    {
        long long tmp = 0;
        for (int i = 0; i < 60; ++i) {
            if ((K >> i) & 1LL) {
                tmp += (N - keta[i]) * (1LL << i);
            } else {
                tmp += keta[i] * (1LL << i);
            }
        }
        res = max(res, tmp);
    }

    cout << res << endl;
    //cout << "sum 0 to 99999: " << (long long)(0 + 99999) * 100000LL / 2LL << endl;
    return 0;
}