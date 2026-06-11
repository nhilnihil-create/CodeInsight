#include <iostream>

using namespace std;

int main() {
    int a, b, c, x;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;
    int n = 0;
    for (size_t i = 0; i <= a; ++i) {
        int tmp_i = x - 500 * i;
        for (size_t j = 0; j <= b; ++j) {
            int tmp_j = tmp_i - 100 * j;
            for (size_t k = 0; k <= c; ++k) {
                if (tmp_j - 50 * k == 0) ++n;
            }
        }
    }
    cout << n << endl;
    return EXIT_SUCCESS;
}