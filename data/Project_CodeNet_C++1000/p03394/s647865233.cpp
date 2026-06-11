#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, nums[8];
    cin >> n;
    if (n == 3) {
        auto list = {2, 5, 63};
        copy(begin(list), end(list), nums);
    } else if (n % 2 == 0) {
        auto list = {2, 10, 3, 9, 4, 8, 6, 12};
        copy(begin(list), end(list), nums);
    } else {
        auto list = {6, 2, 10, 3, 9, 4, 8, 12};
        copy(begin(list), end(list), nums);
    }
    for (int i = 0; i < n; i++) {
        cout << nums[i % 8] + i / 8 * 12 << ' ';
    }
    return 0;
}
