#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(){
	ll n, sum=0;
	cin >> n;

	for(ll i=1; i<=(int)pow(n,0.5); i++){
		if(!(n%i)){		
			ll res = n/i-1;
			if(res>i) sum+=n/i-1;
		}
	}
	
	cout << sum << endl;

	return 0;
}