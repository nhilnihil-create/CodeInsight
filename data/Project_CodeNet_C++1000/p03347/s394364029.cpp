#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main(){
    ll n, ans = 0;   cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (ll i = n-1; i >= 0; i--) {
        if (i-(a[i]-1) < 1) {
            cout << -1 << endl;
            return 0;
        }

        if (i+1 < n && a[i] < a[i+1]-1) {
            cout << -1 << endl;
            return 0;
        }

        if (i+1 < n && a[i+1] - 1 == a[i])
            continue;

        ans += a[i];
    }

    cout << ans << endl;
    return 0;
}