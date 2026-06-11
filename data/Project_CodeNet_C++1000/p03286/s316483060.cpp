#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    ll n;
    cin >> n;
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    stack<int> ans;
    while (n != 0) {
        ll q = n % 2;
        if (q < 0) q += 2;
        ans.push(q);
        n = (n - q) / -2;
    }
    while (!ans.empty()) {
        cout << ans.top();
        ans.pop();
    }
}
