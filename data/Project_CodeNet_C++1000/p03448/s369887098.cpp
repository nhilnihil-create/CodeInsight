#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (n); ++i)


int main() {
    int a, b, c, x;
    cin >> a >> b >> c >> x;
    int count = 0;
    rep(i, a+1) rep(j, b+1) rep(k, c+1) {
        if (i * 500 + j * 100 + k * 50 == x) count++;
    }
    cout << count << endl;
    return 0;
}