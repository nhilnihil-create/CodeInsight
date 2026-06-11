#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void) {
    ll n;
    cin >> n;
    vector<ll> a(n);
    for (int i=0; i<n; i++) cin >> a[i];
    cout << *max_element(a.begin(), a.end()) - *min_element(a.begin(), a.end()) << endl;
    return 0;
}