#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll a[102];
int main() {
	ll n;
	cin>>n;
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	ll ans=0;
	for(ll i=1;i<n;i++){
		if(a[i]==a[i-1]){
			ans++;
			a[i]=101;
		}
	}
	cout <<ans;
	// your code goes here
	return 0;
}