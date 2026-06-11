#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>
using namespace std;

int main() {
    cout << fixed << setprecision(9);

    constexpr int log2_1e5 = 17;

    auto log2 = [](int k, int p) {
        int c = 0, v = p;
        while (v < k) {
            ++c;
            v *= 2;
        }
        return c;
    };

    int n, k; cin >> n >> k;

    int64_t sum = 0;
    for (int i = 0; i < n; ++i) {
        sum += pow(2, log2_1e5 - log2(k, i + 1));
    }

    cout << (sum / (n * pow(2, log2_1e5))) << endl;
}

