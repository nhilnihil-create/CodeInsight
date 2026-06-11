#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

int main() {
    ll n, k, ans = 0;    cin >> n >> k;
    vector<ll> num(k, 0);

    for (int i = 1; i <= n; i++)
        num[i%k]++;

    for (ll a = 0; a < k; a++) {
        if ((k-a)%k*2%k == 0)
            ans += num[a] * num[(k-a)%k] * num[(k-a)%k];
        }

    cout << ans << endl;
    return 0;
}