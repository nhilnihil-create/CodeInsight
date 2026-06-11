#include <iostream>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    size_t d, x;
    cin >> d >> x;
    unsigned long long sum = x;
    for (size_t i = 0; i < n; ++i) {
        size_t a;
        cin >> a;
        for (size_t j = 0; j < d; ++j) {
            if (j * a + 1 <= d) {
                ++sum;
            }
            else {
                break;
            }
        }
    }
    cout << sum << endl;
    return EXIT_SUCCESS;
}