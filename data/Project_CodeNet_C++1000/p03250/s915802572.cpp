#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c; cin >> a >> b >> c;

    if (a >= b && a >= c) {
        cout << 10*a + b + c << endl;
    }
    else if (b >= a && b >= c) {
        cout << 10*b + a + c << endl;
    }
    else { // max:c
        cout << 10*c + a + b << endl;
    }
}