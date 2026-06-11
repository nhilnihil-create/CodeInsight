#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, b, c;
    cin >> a >> b >> c;
    if (a == b && a == c) {
        cout << "Yes\n";
    }
    else {
        cout << "No\n";
    }
}