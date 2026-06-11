#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define MOD 1000000007

int main(void) {
    ll K, A, B;
    cin >> K >> A >> B;
    if(B - A <= 2 || K < A - 1) {
        cout << K + 1 << endl;
    } else {
        ll temp;
        temp = max(0LL, (K - A + 1) / 2);
        cout << A + temp * (B - A) + ((K - A - 1) % 2 ? 1 : 0) << endl;
    }
    return 0;
}
