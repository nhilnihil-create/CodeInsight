#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)
#define rep1(i, n) for (int i = 1; i <= n; ++i)

int main() {
    int a, p;
    cin >> a >> p;
    if (a < 0 && p < 2)
        cout << 0 << endl;
    cout << (3 * a + p) / 2 << endl;
    return 0;
}