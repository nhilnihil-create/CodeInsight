#include <bits/stdc++.h>
using namespace std;

int a[2][8] = {{2, 10, 3, 9, 4, 8, 6, 12}, {6, 2, 10, 3, 9, 4, 8, 12}};

int main() {
    int n; cin >> n;
    if (n == 3) {
        cout << "2 5 63"; return 0;
    }
    for (int i = 0; i < n; i++) {
        cout << a[n & 1][i & 7] << " ";
        a[n & 1][i & 7] += 12;
    }
    return 0;
}