#include <bits/stdc++.h>
using namespace std;
#define repl(i, l, r) for (ll i = (l); i < (r); i++)
#define rep(i, n) repl(i, 0, n)
using ll = long long;

int main() {
    int N;
    cin >> N;
    if (N == 1) {
        cout << 1 << endl;
    }
    else {
        ll temp0 = 2, temp1 = 1, temp = 0;
        rep(i, N - 1) {
            temp = temp1 + temp0;
            temp0 = temp1;
            temp1 = temp;
        }
        cout << temp << endl;
    }
}
