#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, m;
	cin>>n>>m;
	ll t = 1900*m + 100*(n - m);
	while(m--)t <<= 1;
	cout<<t<<endl;

	return 0;
}