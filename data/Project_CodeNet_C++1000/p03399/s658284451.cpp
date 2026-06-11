#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    int A, B, C, D;
    int train = 0;
    int bus = 0;
    cin >> A >> B >> C >> D;
    if (A > B) {
        train = B;
    } else {
        train = A;
    }
    if (C > D) {
        bus = D;
    } else {
        bus = C;
    }

    cout << train + bus << endl;
    return 0;
}