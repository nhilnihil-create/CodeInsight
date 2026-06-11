#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll pre[200005];

ll getsum(int l, int r){
    return pre[r] - pre[l-1];
}

ll uradi(ll i, ll j, ll k, ll l){
    ll a = pre[i];
    ll b = pre[j] - pre[i];
    ll c = pre[k] - pre[j];
    ll d = pre[l] - pre[k];
    ll mn = min(min(min(a, b), c), d);
    ll mx = max(max(max(a, b), c), d);
    return mx - mn;
}

int main(){

    int n;
    cin >> n;
    for(int i=1; i<=n; i++){
        int x;
        cin >> x;
        pre[i] = pre[i-1] + x;
    }
    int l=1, r=3;
    ll res = pre[n];
    for(int middle=2; middle<=n-2; middle++){
        while(l+1 < middle && abs(getsum(1, l+1) - getsum(l+2, middle)) < abs(getsum(1, l) - getsum(l+1, middle))) l++;
        r = max(r, middle+1);
        while(r+1 < n && abs(getsum(middle+1, r+1) - getsum(r+2, n)) < abs(getsum(middle+1, r) - getsum(r+1, n))) r++;
        res = min(res, uradi(l, middle, r, n));
    }
    cout << res;
    return 0;
}
