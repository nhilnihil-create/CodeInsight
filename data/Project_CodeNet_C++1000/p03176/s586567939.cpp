#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
// #define endl "\n"

ll left(ll i) {
    return 2*i+1;
}

ll right(ll i) {
    return 2*i + 2;
}

ll update(ll low, ll high, ll i, ll updatepos, ll updateval, vector<ll>& tree) {
    if (low == high) {
        return tree[i] = updateval;
    }

    ll mid = (low + high)/2;
    ll a, b;
    if (updatepos > mid) {
        a = tree[left(i)];
        b = update(mid+1, high, right(i), updatepos, updateval, tree);
    } else {
        a = update(low, mid, left(i), updatepos, updateval, tree);
        b = tree[right(i)];
    }
    return tree[i] = max(a, b);
}

ll query(ll low, ll high, ll i, ll l, ll r, vector<ll>& tree) {
    if (low > r || high < l) {
        return 0;
    }

    if (low >= l && high <= r) {
        return tree[i];
    }

    ll mid = (low+high)/2;
    ll a = query(low, mid, left(i), l, r, tree);
    ll b = query(mid+1, high, right(i), l, r, tree);
    return max(a, b);

}

int main(void) {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // cout.tie(NULL);
    ll n;
    cin >> n;
    vector<ll> height (n);
    vector<ll> weight (n);
    for (ll i = 0; i < n; i++) {
        cin >> height[i];
    }
    for (ll i = 0; i < n; i++) {
        cin >> weight[i];
    }

    
    vector<ll> tree (4 * n + 10, 0);

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        ll prev = query(0, n, 0, 0, height[i]-1, tree);
        ll now = prev + weight[i];
        ans = max(ans, now);
        update(0, n, 0, height[i], now, tree);
    }
    cout << ans << endl;

    
    return 0;
}