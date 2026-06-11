#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();
#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll  long long int
#define mod  1000000007



int main()
{
	FAST;
	ll n, m;
	cin >> n >> m;
	vector<ll> v;
	for(ll i = 1; i * i < m; i ++){
		if(m % i == 0){
			v.push_back(i);
			v.push_back(m / i);
		}
	}
	if(floor(sqrt(m)) == ceil(sqrt(m))){
		v.push_back(sqrt(m));
	}
	sort(v.begin(), v.end());
	for(ll i = 0; i < v.size(); i ++){
		ll x = v[i];
		if(n <= v[i]){
			cout << m / v[i]; return 0;
		}
	}
	cout  << 1;
}