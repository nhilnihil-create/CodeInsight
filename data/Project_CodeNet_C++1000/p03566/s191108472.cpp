#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<double> t(N);
    vector<double> v(N);

    for(int i = 0; i < N; i++) cin >> t[i];
    for(int i = 0; i < N; i++) cin >> v[i];

    vector<double> x(N + 1);

    x[0] = 0;
    x[N] = 0;

    for(int i = 1; i < N; i++) {
        x[i] = min(v[i - 1], v[i]);
    }

    for(int i = 1; i < N; i++) {
        x[i] = min(x[i], x[i - 1] + t[i - 1]);
        x[N - i] = min(x[N - i], x[N - i + 1] + t[N - i]);
    }

    double ans = 0;

    for(int i = 0; i < N; i++) {
        double d = t[i] - (v[i] - x[i]) - (v[i] - x[i + 1]);
        double f = min(x[i], x[i + 1]);
        double b = max(x[i], x[i + 1]);
        if(d >= 0) {
            ans += t[i] * v[i];
            ans -= (v[i] - f) * (v[i] - f) / 2.0;
            ans -= (v[i] - b) * (v[i] - b) / 2.0;
        } else {
            ans += t[i] * f;
            ans += t[i] * t[i] / 2.0;
            ans -= (f + t[i] - b) * ((f + t[i] - b) / 2.0) / 2.0;
        }
    }

    cout << fixed << setprecision(60) << ans << endl;
}