#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

typedef long long ll;

int main() {
    int n;  cin >> n; 
    vector<long long> a(n), b(n), c(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        ans -= b[i];
        c[i] = a[i] + b[i];
    }
    
    sort(c.begin(), c.end(), greater<ll>());

    for (int i = 0; i < n; i += 2) 
        ans += c[i];

    cout << ans << endl;
    return 0;
}