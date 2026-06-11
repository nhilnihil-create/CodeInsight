#include <iostream>

using namespace std;

int main() {
    size_t a, b, c;
    cin >> a >> b >> c;
    size_t op = 0;
    while (!(a == b && b == c && c == a)) {
        size_t array[3] = {a, b, c};
        size_t max_index = (a >= b && a >= c) ? 0 : (b >= a && b >= c) ? 1 : 2;
        size_t min_index = (a < b && a < c) ? 0 : (b < a && b < c) ? 1 : 2;
        if (array[max_index] - array[min_index] >= 2) {
            ((min_index == 0) ? a : (min_index == 1) ? b : c) += 2;
            ++op;
        }
        else {
            if (max_index == 0) {
                ++b;
                ++c;
            }
            else if (max_index == 1) {
                ++a;
                ++c;
            }
            else {
                ++a;
                ++b;
            }
            ++op;
        }
    }
    cout << op << endl;
    return EXIT_SUCCESS;
}