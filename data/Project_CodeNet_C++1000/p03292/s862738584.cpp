#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;
    int d1 = abs(a - b);
    int d2 = abs(b - c);
    int d3 = abs(c - a);
    int sum = d1 + d2 + d3 - max(d1, max(d2, d3));
    cout << sum << endl;
}
