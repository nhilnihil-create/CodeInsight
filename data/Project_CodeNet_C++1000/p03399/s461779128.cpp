#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ftravel = 0;
    if (a >= b) {
        ftravel = b;
    } else {
        ftravel = a;
    }
    if (c >= d) {
        ftravel = ftravel + d;
    } else {
        ftravel = ftravel + c;
    }
    cout << ftravel;
}