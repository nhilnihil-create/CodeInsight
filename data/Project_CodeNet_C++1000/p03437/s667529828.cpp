#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long x, y; cin >> x >> y;
    cout << (x % y == 0 ? -1 : x) << endl;
    return 0;
}
