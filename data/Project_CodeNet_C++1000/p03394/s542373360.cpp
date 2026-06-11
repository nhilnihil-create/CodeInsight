#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    if (n == 3) {
        cout << "2 5 63" << '\n';
        return 0;
    }
    int a = 0, b = n;
    for (int i = 2; i <= 30000; i += 2) {
        a++;
        b--;
        if (a % 3 != 1 && b % 2 == 0 && 2 <= b && b <= 5000) {
            break;
        }
    }
    // vector<ll> ans;
    for (int i = 2; i <= 30000; i++) {
        if (a != 0 && i % 2 == 0) {
            cout << i << " ";
            // ans.emplace_back(i);
            a--;
        } else if (b != 0 && i % 3 == 0 && i % 2 != 0) {
            cout << i << " ";
            // ans.emplace_back(i);
            b--;
        }
    }
    cout << '\n';
    return 0;
}