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
	if(n > m)swap(n, m);
	if(n == 1){
		if(m == 1)cout<<1<<endl;
		else cout<<m - 2<<endl;
		exit(0);
	}
	if(n == 2){
		cout<<0<<endl;
		exit(0);
	}
	cout<<(n - 2)*(m - 2)<<endl;

	return 0;
}