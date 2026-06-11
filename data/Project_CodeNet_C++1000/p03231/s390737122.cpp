#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5 + 5;

char a[N], b[N];
ll ans;
int n, m; 

ll gcd(ll a, ll b) { return (a%b == 0)? b : gcd(b, a%b); }

int main() {
	cin>>n>>m>>a>>b;
	ans = (ll) n*m/gcd(n, m);
	ll x = ans/n, y = ans/m;
	ll len = x*y/gcd(x, y);
	for(int i = 0; i*len/x < n && i*len/y < m; i++) {
		if(a[i*len/x] != b[i*len/y]) {
			cout<<-1<<endl;
			return 0;
		} 
	}
	cout<<ans<<endl;
}
