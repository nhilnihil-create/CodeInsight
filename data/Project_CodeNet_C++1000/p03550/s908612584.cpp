#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007 

ll c[20001];
int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	ll ans=0;
	for(ll i=0;i<n;i++){
		cin>>c[i];
	}
	ans=max(ans,abs(b-c[n-1]));
	if(n!=1){
	ans=max(ans,abs(c[n-1]-c[n-2]));
	}
	cout <<ans;
	// your code goes here
	return 0;
}