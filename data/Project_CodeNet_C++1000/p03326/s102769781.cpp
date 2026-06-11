#include <iostream>
#include <queue>
#include <tuple>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

int main () {

    int n,m;
    cin >> n >> m;
    tuple<ll,ll,ll> item_table[n];

    rep(i, n) {
        ll a,b,c;
        cin >> a >> b >> c;
        item_table[i] = make_tuple(a,b,c);
    }

    ll a_total,b_total,c_total;
    // abc 0 ... 負, 1 ... 正
    // 000
    // 001
    // 010
    // 011
    // 100
    // 101
    // 110
    // 111

    priority_queue<ll>  sum_q;
    rep(i, 8) { // 0 ... 7
        ll sign_symbol_a = i & 0b001 ? 1 : -1;
        ll sign_symbol_b = i & 0b010 ? 1 : -1;
        ll sign_symbol_c = i & 0b100 ? 1 : -1;

        priority_queue<ll> tmp_q;
        rep(j, n) {
            tmp_q.push( sign_symbol_a * get<0>(item_table[j]) +
                        sign_symbol_b * get<1>(item_table[j]) +
                        sign_symbol_c * get<2>(item_table[j]) );
        }

        ll tmp_sum = 0;
        rep(j, m) {
            tmp_sum += tmp_q.top();
            tmp_q.pop();
        }

        sum_q.push(tmp_sum);
    }

    cout << sum_q.top() << endl;
    return 0;
}
