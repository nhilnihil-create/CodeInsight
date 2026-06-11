/*input
6
4 6 0 0 3 3
0 5 6 5 0 3

5
1 2 3 4 5
1 2 3 4 5
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

const ll N = 200005;
ll a[N], b[N], aa[N], bb[N];
ll n;

ll low_binary(ll pos, ll value){
	ll lo = 0, hi = n - 1, mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(aa[pos] + bb[mid] >= value){
			res = mid;
			hi = mid - 1;
		}
		else{
			lo = mid + 1;
		
		}
	}
	return res;
}

ll high_binary(ll pos, ll value){
	ll lo = 0, hi = n - 1, mid, res = -1;
	while(lo <= hi){
		mid = (lo + hi) >> 1;
		if(aa[pos] + bb[mid] >= value){
			hi = mid - 1;
		}
		else{
			res = mid;
			lo = mid + 1;
		}
	}
	return res;
}

int main(){
	ll i, bit;
	ll ans = 0;
	cin >> n;
	for(i = 0; i < n; ++i)cin >> a[i];
	for(i = 0; i < n; ++i)cin >> b[i];
	for(bit = 0; bit < 40; ++bit){
		ll T = (1LL << bit);
		for(i = 0; i < n; ++i){
			aa[i] = a[i] % (2*T);
			bb[i] = b[i] % (2*T);
		}

		sort(bb, bb + n);

		// for(i = 0; i < n; ++i)cout << aa[i] << " ";
		// cout << endl;
		// for(i = 0; i < n; ++i)cout << bb[i] << " ";
		// cout << endl;

		ll ct = 0, lower_bound, upper_bound;

		for(i = 0; i < n; ++i){
			lower_bound = low_binary(i, T);
			upper_bound = high_binary(i, 2*T);
			if(lower_bound != -1)
				ct = ct + (upper_bound - lower_bound + 1);
			lower_bound = low_binary(i, 3*T);
			upper_bound = high_binary(i, 4*T);
			if(lower_bound != -1)
				ct = ct + (upper_bound - lower_bound + 1);	
		}


		if(ct & 1)
			ans = ans + T;
	}
	cout << ans << endl;
	return 0;
}