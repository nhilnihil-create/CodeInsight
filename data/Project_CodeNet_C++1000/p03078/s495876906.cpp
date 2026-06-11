#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll x, y, z, k;
	cin >> x >> y >> z >> k;
	vector <ll> X, Y, Z;
	for(ll i = 0; i < x; i++){
		ll a;
		cin >> a;
		X.push_back(a);
	}
	for(ll i = 0; i < y; i++){
		ll a;
		cin >> a;
		Y.push_back(a);
	}
	for(ll i = 0; i < z; i++){
		ll a;
		cin >> a;
		Z.push_back(a);
	}
	sort(X.begin(), X.end(), greater<ll>{});
	sort(Y.begin(), Y.end(), greater<ll>{});
	sort(Z.begin(), Z.end(), greater<ll>{});
	set <tuple <ll, ll, ll> > uniq;
	vector <ll> largest;
	priority_queue <tuple <ll, ll, ll, ll> > pq;
	pq.emplace(X[0] + Y[0] + Z[0], 0, 0, 0);
	uniq.insert(make_tuple(0, 0, 0));
	for(ll i = 0; i < k; i++){
		ll sum, xi, yi, zi;
		tie(sum, xi, yi, zi) = pq.top();
		largest.push_back(sum);
		pq.pop();
		if(xi < x - 1){
			ll orig = uniq.size();
			uniq.insert(make_tuple(xi + 1, yi, zi));
			if(uniq.size() > orig) pq.emplace(X[xi + 1] + Y[yi] + Z[zi], xi + 1, yi, zi);
		}
		if(yi < y - 1){
			ll orig = uniq.size();
			uniq.insert(make_tuple(xi, yi + 1, zi));
			if(uniq.size() > orig) pq.emplace(X[xi] + Y[yi + 1] + Z[zi], xi, yi + 1, zi);
		}
		if(zi < z - 1){
			ll orig = uniq.size();
			uniq.insert(make_tuple(xi, yi, zi + 1));
			if(uniq.size() > orig) pq.emplace(X[xi] + Y[yi] + Z[zi + 1], xi, yi, zi + 1);
		}
	}
	for(ll i = 0; i < k; i++){
		cout << largest[i] << '\n';
	}
}