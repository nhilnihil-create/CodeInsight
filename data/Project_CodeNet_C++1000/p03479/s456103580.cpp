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

	ll x, y;
	cin>>x>>y;
	int ret = 1;
	while(2*x <= y){
		x *= 2;
		ret++;
	}
	cout<<ret<<endl;

	return 0;
}