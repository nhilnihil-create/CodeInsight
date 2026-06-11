#include <iostream>
#include <algorithm>
#include <cmath>
#include<iomanip>
using namespace std;
typedef long long ll;
ll n;
ll t[108], v[108], s[108], p[40008];

int main() {
	cin >> n;
	s[0] = 0;
	for(ll i = 1; i <= n; i++){cin >> t[i]; t[i] *= 2; s[i] = s[i-1]+t[i];}
	v[0] = 0; v[n+1] = 0;
	for(ll i = 1; i <= n; i++){cin >> v[i]; v[i] *= 2;}
	for(ll i = 0; i <= s[n]; i++){
		for(ll j = 1; j <= n; j++){if(s[j] >= i){p[i] = v[j]; break;}}
		for(ll j = 0; j <= n; j++){
			ll dist = abs(s[j]-i);
			p[i] = min(p[i], dist+min(v[j], v[j+1]));
		}
	}
	ll sum = 0;
	for(ll i = 0; i <= s[n]; i++){sum += p[i];}
	cout << fixed << setprecision(15) << (double)sum/4;
	return 0;
}