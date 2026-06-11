#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    long long N, K;
    cin >> N >> K;
    
    double res = 0.0;
    for (long long n = 1; n <= N; ++n) {
        double tmp = 1.0;
        long long nn = n;
        while (nn < K){nn *= 2; tmp /= 2.0;}
        res += tmp;
    }
    res /= N;
    cout << fixed << setprecision(10) << res << endl;
}