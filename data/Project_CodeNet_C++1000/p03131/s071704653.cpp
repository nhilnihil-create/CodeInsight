#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair< int, int >;

int main() {
    ll K, A, B;
    cin >> K >> A >> B;

    ll num = 1LL;
    while (K > 0LL) {
        if (num < A) {
            ++num;
            --K;
        } else if ((num >= A) && (K >= 2LL) && (A + 2LL < B)) {
            num -= A;
            num += B;
            K -= 2LL;
        } else {
            ++num;
            --K;
        }
    }
    cout << num << endl;
}