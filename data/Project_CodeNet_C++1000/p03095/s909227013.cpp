// n文字すべてが異なるとすると、答えはcomb(n,1) + comb(n,2) + comb(n,3) + ... + comb(n,n) = 2^n - 1
// ここから、同じ文字を選んだ組み合わせの数を引けば答えになりそう。
// →違った。その考えだと、ある文字を二つ以上選ぶ通りと別の文字を二つ以上選ぶ通りに共通部分が生じ、数え上げが困難になってしまう。
// ある文字cについて、2文字以上使わない条件を満たす、文字cの選び方は、(cの出現回数 + 1)
// (どれか1つを取るケース及び文字cを取らないケース)
// すると、答えは、Π(cの出現回数 + 1) - 1となる
// 最後に引いた1は、空文字列の場合
#include <bits/stdc++.h>
using namespace std;

int alphabet['z' - 'a' + 1];
const long long MOD = 1000000007;

int main() {
    int N;
    string S;
    cin >> N >> S;

    for(auto &p : S) ++alphabet[p - 'a'];
    long long res = 1;
    for(int i = 0; i < 'z' - 'a' + 1; ++i) {
        res *= (alphabet[i] + 1);
        res %= MOD;
    }
    cout << (res - 1 + MOD)%MOD << endl;
    return 0;
}