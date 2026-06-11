#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main() {
    int N, K;

    cin >> N >> K;
    double res = 0;
    for (int i = 1; i <= N; i++) {
        double temp = 1.0 / N;
        int point = i;
        while (point < K) {
            temp *= 0.5;
            point *= 2;
        }
        res += temp;
    }
    cout << setprecision(12) << res << endl;
}