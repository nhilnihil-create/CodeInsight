#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

ll gcd(ll x, ll y) {
    return y ? __gcd(y, x % y) : x;
}

ll lcm(ll x, ll y) {
    return x/__gcd(x, y)*y;
}

int main() {
    ll N; cin >> N;
    ll gcd_num;
    for (int i = 0; i < N; ++i) {
        ll A; cin >> A;
        if (i == 0) gcd_num = A;
        else gcd_num = gcd(gcd_num, A);
    }
    cout << gcd_num << endl;
}