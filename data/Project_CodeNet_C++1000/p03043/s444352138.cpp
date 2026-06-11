#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n, k;
    double win = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        int temp = i;
        while (temp < k) {
            temp *= 2;
            cnt++;
        }
        win += 1.0 / pow(2, cnt);
    }
    cout << setprecision(15) << win / n << endl;
    return 0;
}