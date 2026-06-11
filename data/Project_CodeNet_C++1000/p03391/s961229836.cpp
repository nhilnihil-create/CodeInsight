#include <iostream>
using namespace std;
int main() {
    int n; cin >> n;
    long long ans = 0;
    bool distinct = false;
    int bmin = 1<<30;
    while (n--) {
        int a, b; cin >> a >> b;
        ans += a;
        if (a > b) bmin = min(bmin, b);
    }
    cout << (bmin < 1<<30 ? ans-bmin : 0) << endl;
}
