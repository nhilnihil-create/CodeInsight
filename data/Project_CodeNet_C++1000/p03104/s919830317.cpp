#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

long long x(long long a) {
    if (a % 4 == 0) return a;
    if (a % 4 == 1) return 1;
    if (a % 4 == 2) return a + 1;
    return 0;
}
int main() {
    long long a, b;
    cin >> a >> b;
    cout << (x(b) ^ x(a - 1)) << endl;
}