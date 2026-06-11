#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastio ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
const int maxn = 1e9 + 5;
#define INF 100000000000
const int MOD = 1e9+7;
const double PI = 3.14159265358979323846264338;
const ll MAXN = 1e18;

int n,x[1 << 18],y[1 << 18],t[1 << 18];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fastio
	cin >> n;
	bool ok = true;
	for(int i=1; i<=n; i++){
		cin >> t[i] >> x[i] >> y[i];
	}
	for(int i=1; i<=n; i++){
		int suma = t[i]-t[i-1];
		int ama = abs(x[i]-x[i-1])+abs(y[i]-y[i-1]);
		if(ama>suma || (suma-ama)%2 != 0){
			ok = false;
		}else{
			true;
		}
	}
	if(ok){
		cout << "Yes\n";
	}else{
		cout << "No\n";
	}
	return 0;
}
//^-^