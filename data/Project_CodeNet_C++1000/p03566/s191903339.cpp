#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> t(N);
    vector<double> v(N);
    for (int i = 0; i < N; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> v[i];
    }
    int sum = accumulate(t.begin(), t.end(), 0);
    vector<double> maxv(40010, 0);
    double TIME = 0;
    for (int i = 0; i < N; i++) {
        for (double j = TIME + 0.5; j <= TIME + t[i]; j += 0.5) {
            int k = j * 2;
            if (j == TIME + t[i]) {
                maxv[k] = min({v[i], v[i + 1], maxv[k - 1] + 0.5});
            } else {
                maxv[k] = min(v[i], maxv[k - 1] + 0.5);
            }
        }
        TIME += t[i];
    }
    TIME = sum;
    maxv[TIME * 2] = 0;
    for (int i = N - 1; i >= 0; i--) {
        for (double j = TIME; j >= TIME - t[i] + 0.5; j -= 0.5) {
            int k = j * 2;
            if (maxv[k] < maxv[k + 1] + 0.5) continue;
            maxv[k] = min({v[i], maxv[k], maxv[k + 1] + 0.5});
        }
        TIME -= t[i];
    }
    double ans = 0;
    for (int i = 1; i <= sum * 2; i++) {
        if (maxv[i - 1] != maxv[i]) {
            ans += (maxv[i - 1] + maxv[i]) * 0.5 / 2.0;
        } else {
            ans += maxv[i] * 0.5;
        }
    }

    cout << setprecision(15) << ans << endl;
}