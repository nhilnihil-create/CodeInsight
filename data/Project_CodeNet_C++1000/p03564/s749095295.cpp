#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int now = 1;

    for (int i = 0; i < n; i++) {
        if (now < k) {
            now = now * 2;
        } else {
            now += k;
        }
    }

    cout << now << endl;
    return 0;
}