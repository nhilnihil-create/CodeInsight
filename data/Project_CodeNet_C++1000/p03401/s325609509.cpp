#include <bits/stdc++.h>
using namespace std;

#define all(v) v.begin(), v.end()
#define V vector
#define P pair
typedef long long ll;

int main() {
    int n; cin >> n;
    V<ll> a(n + 2, 0);
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += abs(a[i] - a[i - 1]);
    }
    sum += abs(a[n]);

    for(int i = 1; i <= n; i++){
        cout << sum + abs(a[i - 1] - a[i + 1]) - (abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1])) << endl;

    }
}
