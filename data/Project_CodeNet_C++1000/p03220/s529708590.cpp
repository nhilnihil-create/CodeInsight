#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    int h, index = 0;
    double min_t = 1000, tmp;
    for (int i = 0; i < n; i++) {
        cin >> h;
        if (abs(a - (t - h * 0.006)) < min_t) {
            index = i + 1;
            min_t = abs(a - (t - h * 0.006));
        }
    }

    cout << index << endl;

    return 0;
}
