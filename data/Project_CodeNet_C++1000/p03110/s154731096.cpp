#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <vector>
using namespace std;
int main() {
    int N; cin >> N;
    long double ans = 0.0;
    vector<pair<double, string>> P(N);
    for (int i = 0; i < N; ++i) {
        cin >> P[i].first >> P[i].second;
        if (P[i].second == "BTC") ans += P[i].first * 380000.0;
        else ans += P[i].first;
    }
    cout << setprecision(6) << ans << endl;
}
