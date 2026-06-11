#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll getMax(vector<ll> &bit, int index) {
    ll maxm = 0;
    while (index > 0) {
        maxm = max (maxm, bit[index]);
        index -= (index & (-index));
    }
    return maxm;
}
void update(vector<ll> &bit, int n, int index, ll val) {
    while (index <= n) {
        bit[index] = max (bit[index], val);
        index += (index & (-index));
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> h(n), a(n);
    for (int i = 0; i < n; i++)
        cin>>h[i];
    for (int i = 0; i < n; i++)
        cin>>a[i];
    vector<ll> bit(n+1, 0);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ll maxm = getMax(bit, h[i]-1);
        update(bit, n, h[i], maxm + a[i]);
        ans = max (ans, maxm + a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}
