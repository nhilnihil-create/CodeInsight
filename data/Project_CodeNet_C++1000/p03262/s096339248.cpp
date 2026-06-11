#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, x, first;
    cin >> n >> x >> first;

    int ret = abs(x - first);
    for (int i = 1; i < n; i++) {
        int a;
        cin >> a;
        ret = __gcd(ret, abs(x - a));
    }

    cout << ret << endl;
    return 0;
}