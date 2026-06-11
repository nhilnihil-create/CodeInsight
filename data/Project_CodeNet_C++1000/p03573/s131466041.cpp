#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
typedef long long ll;
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    if (a == b)
        cout << c << endl;
    else if (a == c)
        cout << b << endl;
    else
        cout << a << endl;

    return 0;
}
