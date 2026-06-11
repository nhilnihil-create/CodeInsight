#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll gcd(ll a,ll b){while(a&&b){if(a>b) a = a%b;else b = b%a;}return a+b;}
ll lcm(ll a,ll b){return a / gcd(a,b) * b;}

int main()
{
	ll n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	ll k = lcm(n, m), d = lcm(k / n, k / m);

	for(ll i = 0; i < k; i += d) {
		if(s[i / (k / n)] != t[i / (k / m)]) {
			cout << -1 << endl;
			return 0;
		}
	} 

	cout << k << endl;

	
}