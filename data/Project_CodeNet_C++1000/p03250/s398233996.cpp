#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    cin >> a >> b >> c;
    int result = 0;
    if (a >= b && a >= c) {
        result = ((a * 10) + b) + c;
    }
    if (b >= a && b >= c) {
        result = ((b * 10) + a) + c;
    }
    if (c >= b && c >= a) {
        result = ((c * 10) + a) + b;
    }
    cout << result;
}