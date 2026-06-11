#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    int vi[101] = {};

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;

        vi[xi] += 1;
    }

    int ans = 0;

    for (int i = 0; i <= 100; i++) {
        if (vi[i] != 0) {
            ans++;
        }
    }

    cout << ans;

    return 0;
}