#include <iostream>
#include <limits>

using namespace std;

int main() {
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    int min_price = numeric_limits<int>::max();
    for (size_t ab = 0; ab <= 2 * max(x, y); ab += 2) {
        int price = ((ab <= 2 * x) ? (x - ab / 2) * a : 0) + ((ab <= 2 * y) ? (y - ab / 2) * b : 0) + c * ab;
        if (price <= min_price) min_price = price;
    }
    cout << min_price << endl;
    return EXIT_SUCCESS;
}