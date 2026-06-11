#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll A,B,C;
int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	for(ll i=0;i<n;i++){
		ll x;
		cin>>x;
		if(x<=a){
			A++;
		}
		else if(x<=b){
			B++;
		}
		else{
			C++;
		}
	}
	cout << min({A,B,C});
	// your code goes here
	return 0;
}