// 6/7
// AGC045-Aのための例題
#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1e9;

ll oddsolve(ll a) {
    return (a + 1) / 2 % 2;
}

ll solve(ll a) {
    if (a % 2) return oddsolve(a);
    else return oddsolve(a + 1) ^ (a + 1);  // a+1の結果からa+1を引く（XORの場合は引くもタスも一緒）
}

int main() {
    ll A, B;
    cin >> A >> B;

    cout << (solve(A - 1) ^ solve(B)) << endl;
}