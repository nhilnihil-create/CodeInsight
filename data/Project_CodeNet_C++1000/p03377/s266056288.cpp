#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    if (c < a) {
        cout << "NO";
        return 0;
    } else if (a + b >= c) {
        cout << "YES";
        return 0;
    } else {
        cout << "NO";
        return 0;
    }
}