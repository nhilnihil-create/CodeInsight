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
    long a;
    cin >> a;
    long minv = a;
    long maxv = a;
    for (int i = 1; i < n; i++) {
        cin >> a;
        if (a < minv) {
            minv = a;
        } else if (a > maxv) {
            maxv = a;
        }
    }
    cout << maxv - minv << endl;
}
