#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t, a;
    cin >> n >> t >> a;

    double x = (t - a) / 0.006;

    int j = -1;
    double min_d = INT_MAX;
    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        double d = abs(x - h);
        if (d < min_d) {
            j = i;
            min_d = d;
        }
    }

    cout << ++j << endl;
}