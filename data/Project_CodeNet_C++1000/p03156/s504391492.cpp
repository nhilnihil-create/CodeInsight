#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	ll A,B,C;
	A=B=C=0;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(x<=a){
			A++;
		}
		else if(x>=b+1){
			C++;
		}
		else{
			B++;
		}
	}
	cout << min({A,B,C});
	// your code goes here
	return 0;
}