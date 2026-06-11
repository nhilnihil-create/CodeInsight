#include <bits/stdc++.h>
using namespace std;
typedef long long ll; 

int main() {
	ll n,a,b,c,d,e;
	cin >> n >> a >> b >> c >> d >> e;
	ll flg = min({a, b, c, d, e});
	if(flg==1){
		cout<< n/flg+4 <<endl;
	} else {
		cout<< n/flg+5 <<endl;
	}
	
	return 0;
}