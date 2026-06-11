#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int n[3];
    rep(0, 3) cin >> n[i];

    sort(n, n + 3);

    cout << (n[0] + (n[1] + n[2] * 10)) << endl;

    return 0;
}