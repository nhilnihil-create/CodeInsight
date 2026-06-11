#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    if (a * b > a + b && a * b > a - b) {
        cout << a * b;
    } else if (a + b > a * b && a + b > a - b) {
        cout << a + b;
    } else {
        cout << a - b;
    }
}