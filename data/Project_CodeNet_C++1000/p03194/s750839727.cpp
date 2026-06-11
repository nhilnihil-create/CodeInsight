#include<iostream>
#include<cmath>
using namespace std;
int main() {
    long long n;
    long long p;
    cin >> n >> p;
    long long cnt = 1;
    if (n == 1) {
        cout << p << endl;
        return 0;
    }
    long long beki = 1;
    for (long long i = 2; p >= pow(i, n); ++i) {
        beki = 1;
        for (int j = 0; j < n; ++j) {
            beki *= i;
        }
        while (1) {
            if (p % beki == 0) {
                p /= beki;
                cnt *= i;
            } else {
                break;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}


