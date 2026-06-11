#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 10005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n, c[MAXX];
vector<ll> adj[MAXX];
bool used[MAXX];


signed main()
{
	FAST;
	ll a, b, r;
	cin >> r >> a >> b;
	c[0] = b;
	for(ll i = 1; i <= 10; i++){
		c[i] = r*c[i-1]  -a;
	}
	for(ll i = 1; i <= 10; i++){
		cout << c[i] << endl;
	}
}