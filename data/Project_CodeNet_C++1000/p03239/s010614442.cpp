#include <bits/stdc++.h>
using namespace std;
#define FAST ios_base::sync_with_stdio(0); cin.tie(); cout.tie();

#define MAXX 500005
#define PI 3.14159265358979323846264338327950
#define F first
#define S second
#define ll   long long int
#define mod  1000000007



int main()
{
	FAST;
	ll n;
	cin >> n;
	ll t;
	cin >> t;
	ll c, d;
	ll mn = 1000;
	bool a = false;
	for(ll i = 0; i < n; i ++){
		cin >> c >> d;
		if(d <= t){
			mn = min(mn, c);
			a = true;
		}
	}
	if(a){
		cout << mn;
	}
	else{
		cout << "TLE";
	}
}