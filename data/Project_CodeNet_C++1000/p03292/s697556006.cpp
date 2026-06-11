#include <bits/stdc++.h>

#define rep(x, y) for (int i = (x); i < (y); i++)

typedef long long ll;

using namespace std;

int main() {
    int a[3];
    rep(0, 3) cin >> a[i];

    sort(a, a + 3);

    int sum = 0;
    rep(1, 3) {
        sum += abs(a[i] - a[i-1]);
    }

    cout << sum << endl;

    return 0;
}