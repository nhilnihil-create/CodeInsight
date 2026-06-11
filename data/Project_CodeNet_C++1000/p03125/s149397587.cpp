#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (b % a == 0) {
        cout << a + b;
    } else {
        cout << b - a;
    }
}