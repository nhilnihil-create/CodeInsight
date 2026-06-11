#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int ,int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 200005

ll n , s;
ll a[MAXX];
ll b[MAXX];

int main()
{
    _FastIO;
    cin >> n;
    ll ans = 0;
    ll m = n / 2;
    for(ll i = 0; i < n; i++){
        cin >> a[i];
        b[i] = a[i] - (i + 1);
    }
    sort(b , b + n);
    for(ll i = 0; i < n; i++){
        ans += abs(b[i] - b[m]);
    }
    cout << ans << endl;
    return 0;
}
