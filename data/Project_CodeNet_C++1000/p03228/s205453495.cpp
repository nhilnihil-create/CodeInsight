#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0, i##_len = (int)(n); i < i##_len; i++)
void f(long &a, long &b) {
    if (a % 2 == 1) a--;
    long x = a / 2;
    a = x;
    b += x;
}
int main() {
    long a, b, k;
    cin >> a >> b >> k;
    rep(i, k) {
        (i % 2 == 0) ? f(a, b) : f(b, a);
    }
    cout << a << " " << b << endl;
}
