#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int minv, maxv;
    minv = min(min(a, b), c);
    maxv = max(max(a, b), c);
    cout << maxv - minv << endl;
    return 0;
}