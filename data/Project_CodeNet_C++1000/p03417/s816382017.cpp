#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;

int main(){
	ll n,m;
	cin >> n >> m;

	if(n==1 && m==1){
		cout << 1 << endl;
	}
	else if(n==1 || m==1){
		ll a = max(n,m);
		cout << a-2 << endl;
	}else{
		cout << (n-2)*(m-2) << endl;
	}
	return 0;
}