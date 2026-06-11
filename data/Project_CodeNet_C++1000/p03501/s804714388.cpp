#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, a, b;
    cin >> n >> a >> b;
    int p = n * a;
    if (p == b) {
        cout << b;
    } else if (p < b) {
        cout << p;
    } else {
        cout << b;
    }
}