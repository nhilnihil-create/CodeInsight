#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <numeric>
#include <cmath>

using namespace std;

typedef long long int ll;

#define all(x) x.begin(),x.end()

const ll mod = 1e9+7;
const ll INF = 1e9;
const ll MAXN = 1e9;

ll S(ll n){
	if(n<10) return n;
	else return n%10+S(n/10);
}

double snuke(pair<ll,ll> p){
	return (double)p.first/p.second;
}

ll f(ll n){

	vector<pair<ll,ll> > res;

	for(int d = 0; d < 15; d++){
		ll x = pow(10,d)*floor((double)n/pow(10,d)+1)-1;
		pair<ll,ll> y;
		y.first = x;
		y.second = S(x);
		res.push_back(y);
	}

	ll m = res[0].first;
	double ms = snuke(res[0]);

	for(int i = 0; i < res.size(); i++){
		if(ms > snuke(res[i])){
			m = res[i].first;
			ms = snuke(res[i]);
		}
	}

	return m;
}

int main()
{
	ll k;
	cin >> k;
	ll a = 1;
	for(int i = 1; i <= k; i++){
		cout << a << endl;
		a = f(a+1);
	}

	return 0;
}
