#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)

int main(){

	ios::sync_with_stdio(false);

	int a, b, t,biscoitos = 0;
	cin >> a >> b >> t;
	
	for(int i=a;i<=t;i+=a) biscoitos += b;

	cout << biscoitos << "\n";
	return 0;
}