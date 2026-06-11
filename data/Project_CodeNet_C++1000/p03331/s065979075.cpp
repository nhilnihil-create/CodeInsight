#include <iostream>
#include <limits>

using namespace std;

int make_sum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n = n / 10;
    }

    return sum;
}

int main() {
    int n;
    cin >> n;
    int min_sum = numeric_limits<int>::max();
    for (int i = 1; i < n; ++i) {
        int sum_a = make_sum(i);
        int sum_b = make_sum(n - i);
        int sum = sum_a + sum_b;
        if (sum < min_sum) min_sum = sum;
    }
    cout << min_sum << endl;
    return EXIT_SUCCESS;
}