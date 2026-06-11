#include <bits/stdc++.h>
using namespace std;
int main() {
    double a, b;
    cin >> a >> b;
    a = (a + b) / 2;
    if (a - floor(a) >= 0.5) cout << ceil(a);
    else cout << floor(a);
}