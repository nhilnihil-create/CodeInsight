#include <iostream>
#include <vector>
#include <algorithm>
#define rep(i, n) for(int i = 0; i < (int)(n); ++i)
#define REP(i, n) for(int i = 1; i < (int)(n); ++i)
using namespace std;

int main() {
    long long N;
    cin >> N;
    
    for (long long h = 1; h <= 3500; ++h) {
        for (long long n = 1; n <= 3500; ++n) {
            if (4 * h * n - N * n - N * h <= 0) continue;
            if (N * h * n < 4 * h * n - N * n - N * h) continue;
            if (N * h * n % (4 * h * n - N * n - N * h) == 0) {
                cout << h << " " << n << " " << N * h * n / (4 * h * n - N * n - N * h) << endl;
                return 0;
            }
        }
    }
}
