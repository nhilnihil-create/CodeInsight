#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    bool enable = false;
    for (size_t i = 0; i <= n; i += 7) {
        if (n == i) {
            enable = true;
            break;
        }
        for (size_t j = 0; j <= n - i; j += 4) {
            if (n - i == j) {
                enable = true;
                break;
            }
        }
        if (enable) break;
    }
    cout << (enable ? "Yes" : "No") << endl;
    return EXIT_SUCCESS;
}