#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

void YesNo(bool x) {
    cout << (x ? "Yes" : "No") << endl;
}

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    cout << min(a, b) + min(c, d) << endl;
    return 0;
}