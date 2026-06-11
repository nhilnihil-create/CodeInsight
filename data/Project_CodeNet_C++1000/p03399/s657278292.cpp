#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int train = min(a, b);
    int bus = min(c, d);
    cout << train + bus << endl;
}