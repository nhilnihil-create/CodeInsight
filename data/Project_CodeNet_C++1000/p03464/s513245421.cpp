#include<bits/stdc++.h>
#define watch(x) cout << (#x) << " is " << (x) << endl
typedef long long ll;
using namespace std;
int static fast = [](){
  ios::sync_with_stdio(false);
  cin.tie(0); cout.tie(0); return 0;
}();

ll bs(vector<ll>& arr, ll x) {
    for(ll val: arr) {
        x -= x % val;
    }
    return x;
}
int main() {
    int k;
    cin >> k;
    vector<ll> arr(k, 0);
    for(auto& val: arr)
        cin >> val;
    ll l = 0, r = (ll)INT_MAX * (ll)(INT_MAX-2);

    ll upper = -1, lower;
    while(l < r) {
        ll mid = l+(r-l)/2;
        ll res = bs(arr, mid);
        // cout << "lower mid " << mid << " =>" << res << endl;
        if (res < 2) {
            l = mid+1;
        } else {
            r = mid;
        }
    }
    lower = l;
    if (bs(arr, lower) != 2) {
        cout << -1 << endl;
        return 0;
    }

    l = 0, r = (ll)INT_MAX * (ll)(INT_MAX-2);
    while(l < r) {
        ll mid = l+(r-l)/2;
        ll res = bs(arr, mid);
        //cout << "upper mid " << mid << " =>" << res << endl;
        if (res > 2) {
            r = mid-1;
        } else {
            l = mid;
            if (l+1 == r) {
                upper = (bs(arr, r) == 2) ? r : l;
                break;
            }
        }
    }
    if (upper == -1)
        upper = l;
    cout << lower << " " << upper << endl;
    return 0;
}

