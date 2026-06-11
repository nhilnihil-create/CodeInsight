#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    double sol = 0;
    for(int i = 1; i <= n; i++) {
        int x = i;
        double val = 1;
        double c = 1.0 / n;
        while(x < k) {
            x *= 2;
            val /= 2;
        }
        //cout << c << ' ' << val << '\n';
        sol += c * val;
    }
    cout << fixed << setprecision(9) << sol;
    return 0;
}