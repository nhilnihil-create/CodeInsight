#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
	ll a,b;
	cin >> a >> b;

	ll ans = 0;
	if(a==b){
		cout << a << endl;
		return 0;
	}

	if(a%2==1){
		ans ^= a;
		a++;
	}
	if(b%2==0){
		ans ^= b;
		b--;
	}
	
	if(a<b) if(((b+1-a)/2)%2==1) ans ^= 1;

	cout << ans << endl;

	return 0;
}