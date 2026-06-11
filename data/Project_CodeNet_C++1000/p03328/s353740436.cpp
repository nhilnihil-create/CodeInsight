#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b; cin >> a >> b;
    int d = b - a;
    cout << (d - 1) * ((d - 1) + 1) / 2 - a << endl;
    return 0;
}
