#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

int main() {
	ll m,k;
	cin>>m>>k;
	ll l=0,r=m;
	for(ll i=0;i<k;i++){
		ll x,y;
		cin>>x>>y;
		l=max(l,x);
		r=min(r,y);
	}
	if(r>=l){
		cout << r-l+1;
	}
	else{
		cout << 0;
	}
	// your code goes here
	return 0;
}