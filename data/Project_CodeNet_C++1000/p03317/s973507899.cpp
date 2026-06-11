#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int divup(int n, int k) {
    return (n + k - 1) / k;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << divup(n - 1, k - 1) << endl;
}
