#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

int main() {
    int n; cin >> n;
    V<ll> a(n);
    ll m = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        m += a[i] - 1;
    }
    cout << m << endl;
}
