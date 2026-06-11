#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n % 2 != 0) {
        n *= 2;
    }
    cout << n;
}
