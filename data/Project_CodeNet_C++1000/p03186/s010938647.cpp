#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a > c) {
        cout << b + c << endl;
        return 0;
    }

    int sum = 0;
    sum = a;
    c -= a;

    if (b >= c) {
        sum += b + c;
    }
    else
        sum += (b *2 + 1);

    cout << sum << endl;
}