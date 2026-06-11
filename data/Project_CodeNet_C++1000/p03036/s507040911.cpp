#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int r, d, x;
    cin >> r >> d >> x;
    for (int i = 0; i < 10; i++) {
        x = r * x - d;
        cout << x << endl;
    }
    return 0;
}