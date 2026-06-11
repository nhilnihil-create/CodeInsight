#pragma GCC optimize("O3") //コンパイラ最適化用

#define _GLIBCXX_DEBUG //配列に[]でアクセス時のエラー表示
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
// forループ関係
//引数は、(ループ内変数,動く範囲)か(ループ内変数,始めの数,終わりの数)、のどちらか
// Dがついてないものはループ変数は1ずつインクリメントされ、Dがついてるものはメントされる
#define REP(i, n) for (ll i = 0; i < ll(n); i++)
#define REPD(i, n) for (ll i = n - 1; i >= 0; i--) //ループ変数は1ずつデクリ
#define FOR(i, a, b) for (ll i = a; i < ll(b); i++)
#define FORD(i, a, b) for (ll i = a; i > ll(b); i--) //ループ変数は1ずつデクリ
// xにはvectorなどのコンテナ
#define ALL(x) x.begin(), x.end() // sortなどの引数を省略したい
#define SIZE(x) ll(x.size())      // sizeをsize_tからllに直しておく
//定数
#define INF 1000000000000 // 10^12:極めて大きい値,∞
#define MOD 1000000007    // 10^9+7:合同式の法
#define MAXR 100000 // 10^5:配列の最大のrange(素数列挙などで使用)
//略記
#define PB push_back // vectorヘの挿入
#define MP make_pair // pairのコンストラクタ
#define F first      // pairの一つ目の要素
#define S second     // pairの二つ目の要素
#define Umap unordered_map
#define Uset unordered_set
#define P pair<ll, ll>
const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000

int main() {
    ll n;
    cin >> n;
    ll set_size;
    bool can = false;

    REP(i, n + 1) {
        if (i * (i + 1) == 2 * n) {
            set_size = i;
            can = true;
            break;
        }
    }

    if (!can) {
        cout << "No" << endl;
    } else if (n == 1) {
        cout << "Yes" << endl;
        cout << 2 << endl;

        cout << 1 << " " << 1 << endl;
        cout << 1 << " " << 1 << endl;

    } else {
        cout << "Yes" << endl;
        cout << set_size + 1 << endl;

        cout << set_size;
        ll pos1 = n - set_size + 1;
        REP(i, set_size) {
            cout << " " << pos1;
            pos1++;
        }
        cout << endl;

        cout << set_size;
        ll pos2 = 1;
        ll diff2 = 1;
        while (pos2 <= n) {
            cout << " " << pos2;
            pos2 += diff2;
            diff2++;
        }
        cout << endl;

        cout << set_size;
        ll pos3 = 1;
        ll diff3 = 2;
        while (pos3 <= n) {
            cout << " " << pos3;
            pos3 += diff3;
            diff3++;
        }
        cout << endl;

        if (set_size >= 3) {
            ll start_pos = 2;
            ll start_pos_diff = 2;
            ll set_number = 1;
            while (start_pos < n - set_size + 1) {
                cout << set_size;

                ll current_set_size = 1;
                ll pos = start_pos;
                while (current_set_size <= set_number + 1) {
                    cout << " " << pos;
                    pos++;
                    current_set_size++;
                }
                ll diff = current_set_size - 1;
                pos--;
                while (pos < n - set_size + 2) {
                    pos += diff;
                    cout << " " << pos;
                    diff++;
                }
                start_pos += start_pos_diff;
                start_pos_diff++;
                set_number++;
                cout << endl;
            }
        }
    }
}
