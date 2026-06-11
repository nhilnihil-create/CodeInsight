#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <string>
#include <math.h>
#define ll long long
#define vl vector<ll>
#define vvl vector<vector<ll> >
#define vvvl vector<vector<vector<ll> > >
#define vd vector<double>
#define vvd vector<vector<double> >
#define vvvd vector<vector<vector<double> > >
#define mod 1000000007
using namespace std;

int main(){
	ll n, k; cin >> n >> k;
	ll ans = 0, e = 0,o = 0;
	for (ll i = k % 2 ? 2 : 1; (i*k)/2 <= n; i+= k % 2 ? 2 : 1){
		if (i % 2) o++;
		else e++;
	}cout << (ll)(pow(o, 3) + pow(e, 3)) << endl;

	return 0;
}