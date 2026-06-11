#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
    int r, D, x; cin >> r >> D >> x;
    vector<int> X(11, 0);
    X[0] = x;
    for (int i = 1; i < 11; i++) {
        X[i] = r * X[i - 1] - D;
        printf("%d\n", X[i]);
    }
}
