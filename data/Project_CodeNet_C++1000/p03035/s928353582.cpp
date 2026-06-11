#include <bits/stdc++.h>
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MAXX 10005
#define PI 3.14159265358979323846264338327950
#define ll signed long long int
using namespace std;
ll t , n;
vector<ll> adj[MAXX];
bool used[MAXX];


signed main()
{
	FAST;
	ll a, b;
	cin >> a >> b;
	if(a >= 13){
		cout << b;
		return 0;
	}
	if(a >= 6){
		cout << b/2;
	}
	else{
		cout << 0;
	}
}