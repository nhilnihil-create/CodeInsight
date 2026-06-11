#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int r, d, x;
    cin >> r >> d >> x;
    vector<int> xx(11, x);
    for (int i = 0; i < 10; i++) {
        xx[i + 1] = r * xx[i] - d;
        cout << xx[i + 1] << endl;
    }
}