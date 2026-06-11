#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
//cout << setprecision(20) << 

int main() {
    ll N; cin >> N;
    ll sum = 0;
    ll max_price = 0;
    for (int i = 0; i < N; ++i) {
        ll price; cin >> price;
        max_price = max(price, max_price);
        sum += price;
    }
    sum -= max_price/2;
    cout << sum << endl;
}