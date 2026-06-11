#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    int k;
    int x[2];
    cin >> x[0] >> x[1] >> k;
    rep(i,k) {
        if (x[i%2] % 2 == 1) x[i%2]--;
        x[i%2] /= 2;
        x[(i%2)^1] += x[i%2];
    }
    cout << x[0] << " " << x[1] << endl;
}