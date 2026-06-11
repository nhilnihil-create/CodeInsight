#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

int main() {
    cin.tie(0); ios::sync_with_stdio(false);
    // cout << setprecision(8) << setiosflags(ios::fixed);

    int a, b;
    cin >> a >> b;
    if (a + b == 15) cout << "+\n";
    else if (a * b == 15) cout << "*\n";
    else cout << "x\n";

    return 0;
}
