#include <bits/stdc++.h>
using namespace std;

set<int> make_divisors(int a) {
    set<int> ret;
    for (int d = 1; d*d <= a; d++) {
        if (a % d == 0) {
            ret.insert(d);
            ret.insert(a / d);
        }
    }
    return ret;
} 

int main() {
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 1; i <= n; i += 2) {
        if (make_divisors(i).size() == 8) {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}