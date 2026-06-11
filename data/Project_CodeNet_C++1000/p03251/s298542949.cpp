#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main() {
    int n, m, x, y;
    cin >> n >> m >> x >> y;

    int x_max = x;
    int y_min = y;

    for (int i = 0; i < n; i++) {
        int xi;
        cin >> xi;

        if (x_max < xi) {
            x_max = xi;
        }
    }

    for (int i = 0; i < m; i++) {
        int yi;
        cin >> yi;

        if (y_min > yi) {
            y_min = yi;
        }
    }

    if (x_max < y_min) {
        cout << "No War";
    } else {
        cout << "War";
    }


    return 0;
}