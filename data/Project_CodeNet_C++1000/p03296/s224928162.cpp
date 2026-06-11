#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <map>
#include<iomanip>
#include<vector>

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
		if(i<n && a[i] == a[i+1]){
			a[i+1]=-1;
			ans++;
		}
	}
	cout<<ans<<endl;
	
}