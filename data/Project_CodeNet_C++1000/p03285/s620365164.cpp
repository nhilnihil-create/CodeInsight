#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < 100; i++) {
        if (4 * i > n) {
            break;
        }

        int m = n - 4 * i;

        if (m % 7 == 0) {
            cout << "Yes";
            return 0;
        }
    }

    cout << "No";
}