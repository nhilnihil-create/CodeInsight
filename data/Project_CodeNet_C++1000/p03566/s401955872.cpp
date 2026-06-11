#include "bits/stdc++.h"
using namespace std;

const long long INF = 5e18;

void solve() {
    int N;
    cin >> N;
    vector<int> t(N);
    vector<double> v(N);
    for (int i = 0; i < N; i++) cin >> t.at(i);
    for (int i = 0; i < N; i++) cin >> v.at(i);
    int t_sum = 0;
    for (int i = 0; i < N; i++) t_sum += t.at(i);
    vector<double> max_speed(0);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < t.at(i); j++) {
            max_speed.push_back(v.at(i));
        }
    }
    max_speed.push_back(0);
    for (int i = max_speed.size() - 2; i >= 0; i--) {
        max_speed.at(i) = min(max_speed.at(i), max_speed.at(i + 1) + 1);
    }
    /*
    for (int i = 0; i < max_speed.size(); i++) cout << max_speed.at(i) << " ";
    cout << endl;
    */
    double ans = 0, speed = 0, x, y;
    for (int i = 0; i < max_speed.size() - 1; i++) {
        x = max_speed.at(i);
        y = max_speed.at(i + 1);
        if (x == speed) {
            if (y < speed) {
                ans += speed - 0.5;
                speed--;
            } else {
                ans += speed;
            }
        } else {
            if (y < speed) {
                ans += speed - 0.5;
                speed--;
            } else if (y > speed) {
                ans += speed + 0.5;
                speed++;
            } else {
                ans += speed + 0.25;
            }
        }
        //cout << ans << " ";
    }
    //cout << endl;
    cout << fixed << ans << endl;
    return;
}

int main() {
    solve();
}
