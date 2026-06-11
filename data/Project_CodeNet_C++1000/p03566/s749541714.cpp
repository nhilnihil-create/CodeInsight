#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;

    int sum = 0;
    vector<int> time(n);
    for (int i = 0; i < n; i++) {
        cin >> time[i];
        sum += time[i];
    }

    vector<double> limit(sum * 2 + 1, 1145141919);
    int now = 0;
    for (int i = 0; i < n; i++) {
        double speed;
        cin >> speed;
        for (int j = 0; j <= time[i] * 2; j++) {
            limit[now] = min(limit[now], speed);
            now++;
        }
        now--;
    }

    vector<double> lmax(sum * 2 + 1);
    for (int i = 1; i <= sum * 2; i++) lmax[i] = min(lmax[i - 1] + 0.5, limit[i]);
    vector<double> rmax(sum * 2 + 1);
    for (int i = sum * 2 - 1; i >= 0; i--)rmax[i] = min(rmax[i + 1] + 0.5, limit[i]);

    double ret = 0;
    for (int i = 1; i <= sum * 2; i++) {
        ret += (min(lmax[i - 1], rmax[i - 1]) + min(lmax[i], rmax[i])) / 2 * 0.5;
    }

    cout << fixed << setprecision(10) << ret << endl;
    return 0;
}