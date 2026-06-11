#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
vector<ll> bit(200010,0);
void init() {
    fill(bit.begin(),bit.end(),0);
}
void add(ll a, ll w) {
	for (ll x = a;x <= n+n+1;x += x&-x) bit[x] += w;
}
ll sum(ll a) {
	ll ret = 0;
	for (ll x = a;x > 0;x -= x&-x) ret += bit[x];
	return ret;
}

int main() {
    cin >> n;
    vector<ll> a(n,0),sums(n+1,0);
    for (ll i = 0;i < n;++i) cin >> a[i];

    ll min = 0,max = *max_element(a.begin(),a.end())+1;

    while (1) {
        ll mid = min+(max-min)/2;
        for (ll i = 0;i < n;++i) sums[i+1] = (mid > a[i]) ? -1 : 1;
        for (ll i = 0;i < n;++i) sums[i+1] += sums[i];

        init();
        ll ret = 0;
        for (ll i = n;i >= 0;--i) {
            ret += n-i-sum(sums[i]+n);
            add(sums[i]+n+1,1);
        }
        //cout << min << " " << max << " " << mid << " " << ret << "\n";
        if (ret < (1+n*(n+1)/2)/2) max = mid;
        else if (min == mid) break;
        else min = mid;
    }
    cout << min << endl;
}