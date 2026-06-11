#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 1; i <= 3500; i++) {
        for (int j = 1; j <= 3500; j++) {
            long long A = 1ll * N * i * j;
            long long B = 4ll * i * j - N * i - N * j;
            if (B != 0 && A % B == 0 && A / B > 0) {
                cout << i << " " << j << " " << A / B << endl;
                return 0;
            }
        }
    }
}
