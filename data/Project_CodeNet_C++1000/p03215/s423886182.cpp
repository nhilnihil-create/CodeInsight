#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
ll n, k, a[1000], sum[1000000], s, o, f, m;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	for(ll i = 0; i < n; i++)
		cin >> a[i];
	f = 0;
	for(ll i = 0; i < n; i++) {
		s = 0;
		for(ll j = i; j < n; j++) {
			s += a[j];
			sum[f] = s;
			f++;
		}
	}
	bool check[f + 1];
	for(ll i = 0; i < f; i++)
		check[i] = true;
	for (ll i = 50; i > 0; i--) {
        o = 0;
        for (ll j = 0; j < f; j++)
            if (check[j])
                if ((sum[j] >> i) & 1) 
                	o++;
        if (o >= k)
            for (ll j = 0; j < f; j++)
                if (check[j])
                    if (!((sum[j] >> i) & 1)) 
                    	check[j] = false;
    }
    ll ans = LLONG_MAX;
    for (ll i = 0; i < f; i++)
        if (check[i]) 
        	ans &= sum[i];
    cout << ans;
}