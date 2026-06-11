#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>

#include <map>
 
using namespace std;
typedef long long ll; 


ll ans,mx,sum,mn=1e18,flag;

int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	for(ll i=0; i<n; i++){
		if(i<n-1) sum += abs(a[i]-a[i+1]);
	}
	sum += abs(a[0])+abs(a[n-1]);
	
	cout<<(sum+abs(a[1])) -(abs(a[0]) + abs(a[0]-a[1]))<<endl;
	
	for(ll i=1; i<=n-2; i++){
		cout<<(sum+abs(a[i-1]-a[i+1])) -(abs(a[i-1]-a[i]) +abs(a[i]-a[i+1]))<<endl;
	}
	cout<<(sum +abs(a[n-2]))-(abs(a[n-2]-a[n-1])+abs(a[n-1]));
}