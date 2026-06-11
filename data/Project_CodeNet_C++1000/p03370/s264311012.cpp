#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    int n;
    int x;
    int min;
    int m;

    cin >> n >> x;

    cin >> m;
    min = m;
    x = x - m;

    for (int i = 0; i < n-1; i++) {
        cin >> m;
        x = x - m;
        if (m < min) {
            min = m;
        }
    }

    if (x > 0) {
        n = n + (x / min);
    }

    cout << n << endl;

    return 0;
}