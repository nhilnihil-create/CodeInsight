#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int h, w, x, y;
    cin >> h >> w >> x >> y;
    cout << (h - x) * (w - y) << endl;
    return 0;
}