#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n;
	cin>>n;
	ll a[100010],b[100010];
	for(ll i=0;i<n;i++){
		cin>>a[i];
	}
	for(ll i=0;i<n;i++){
		cin>>b[i];
	}
	ll A=0,B=0;
	for(ll i=0;i<n;i++){
		if(a[i]>b[i]){
			B+=a[i]-b[i];
		}
		else{
			A+=(b[i]-a[i])/2;
		}
	}
	cout << (B<=A?"Yes":"No");
	// your code goes here
	return 0;
}