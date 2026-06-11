#include <bits/stdc++.h>
using namespace std;

#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

#define MAXX 200005


#define PI 3.14159265358979323846264338327950

#define ll  long long int
vector<ll> v;
multiset<ll> ms;
multiset<ll>::iterator it;
ll a[MAXX], b[MAXX];
ll mod = 1000000007;
char c[MAXX];

int main()
{
	FAST;
	ll  ans = 0, a1 = 0, a2 = 0, n , mx = 0, m = 1;
	cin >> n;
	ms.insert(n);
	while(ms.count(n) < 2){
		if(n % 2 == 0){
			n /= 2;
		}
		else{
			n = 3*n + 1;
			
		}
		ms.insert(n);
		m ++;
	}
	cout << m;
	
}