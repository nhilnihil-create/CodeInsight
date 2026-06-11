#include<bits/stdc++.h>

using namespace std;
using ll = long long int;
#define long ll

int main(void) {
    cin.tie(0); ios::sync_with_stdio(false);

    ll n;
    cin >> n;
    vector<ll> a(n+2);
    for(ll i=0; i<n; i++)
        cin >> a[i+1];

    ll s = 0;
    for(ll i=1; i<n+2; i++)
        s += abs(a[i] - a[i-1]);

    for(ll i=1; i<=n; i++)
        cout << s - (abs(a[i-1] - a[i]) + abs(a[i] - a[i+1])) + abs(a[i+1] - a[i-1]) << endl;
}
