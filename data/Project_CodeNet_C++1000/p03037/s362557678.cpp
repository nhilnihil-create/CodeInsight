#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int maxL = 1, minR = n;
    for (int i = 0; i < m; i++) {
        int L, R;
        cin >> L >> R;

        maxL = max(maxL, L);
        minR = min(minR, R);
    }

    cout << (minR < maxL ? 0 : (minR - maxL) + 1) << endl;
}