#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define mp make_pair

#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()

typedef long long ll;
typedef long double ld;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    ll sum = 0;
    for (auto el : a) sum += el;
    if (sum == x) {
        cout << n;
        return 0;
    }
    int pos = 0;
    sum = 0;
    while (pos < n - 1 && sum + a[pos] <= x) sum += a[pos++];
    cout << pos;
    return 0;
}
