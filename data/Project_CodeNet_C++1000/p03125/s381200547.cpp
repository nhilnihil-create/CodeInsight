#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 100005

#define PI 3.14159265358979323846264338327950

#define ll  long long int
vector<ll> v;
multiset<ll> ms;
multiset<ll>::iterator it;
ll a[MAXX];
int main()
{
	FAST;
	ll n, t, m, o = 1, z, p;
	cin >> n >> m;
	if(m % n == 0){
		cout << m + n;
	}
	else{
		 cout << m -n;
	}
	

}