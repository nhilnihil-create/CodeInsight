#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a;
    cin >> n; 
    vector<double> arr(n);
    double t, min_so_far = 1000000.0;
    int ans = -1;
    cin >> t >> a;

    for (int i = 0; i < n; i++) {
        double x;
        cin >> x;

        if (abs(t - x * 0.006 - a) < min_so_far) {
            min_so_far = abs(t - x * 0.006 - a);
            ans = i + 1;
        }
    }

    cout << ans << endl;

}
