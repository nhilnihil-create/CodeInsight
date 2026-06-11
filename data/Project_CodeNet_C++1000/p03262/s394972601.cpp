#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;
ll MOD = 1e9 + 7;

// int gcd(int a, int b) {
//     if (a < b) swap(a, b);
//     if (a % b)
//         return gcd(b, a % b);
//     else
//         return b;
// }

template <class Type>
Type gcd(Type a, Type b) {
    if (a < b) swap(a, b);
    if (a % b)
        return gcd(b, a % b);
    else
        return b;
}

int main() {
    int n;
    cin >> n;
    vector<int> x(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    vector<int> d(n);
    for (int i = 0; i < n; i++) {
        d[i] = x[i + 1] - x[i];
    }
    int ans = d[0];
    for (int i = 1; i < n; i++) {
        ans = gcd(ans, d[i]);
    }
    cout << ans << endl;
    return 0;
}