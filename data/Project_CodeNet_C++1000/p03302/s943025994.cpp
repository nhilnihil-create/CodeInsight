#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < n; ++i)
typedef long long ll;
using namespace std;
const int INF = 1e9;

int main() {
    int a, b;
    cin >> a >> b;

    if (a + b == 15)
        cout << "+";
    else if (a * b == 15)
        cout << "*";
    else
        cout << "x";
    cout << endl;

    return 0;
}
