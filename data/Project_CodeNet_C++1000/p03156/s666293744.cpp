#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, a, b; cin >> n >> a >> b;

    int p1 = 0, p2 = 0, p3 = 0;
    while (n--) {
        int p; cin >> p;
        p1 += p <= a;
        p2 += a + 1 <= p && p <= b;
        p3 += b + 1 <= p;
    }

    int ans = 0;
    while (p1-- && p2-- && p3--) {
        ++ans;
    }

    cout << ans << endl;
}

