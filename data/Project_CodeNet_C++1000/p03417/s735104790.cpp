#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long h, w; cin >> h >> w;
    cout << abs((h - 2) * (w - 2)) << endl;
    return 0;
}
