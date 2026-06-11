#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){

    int n, k;
    cin >> n >> k;

    vector<ll> h(n);
    for (int i=0; i<n; i++){
        cin >> h.at(i);
    }

    sort(h.begin(), h.end());

    ll ans = 1e9;
    k--;
    for (int i=0; i<n-k; i++){
        ll buf;
        buf = h.at(i+k) - h.at(i);
        ans = min(ans, buf);
    }

    cout << ans << endl;
    return 0;
}