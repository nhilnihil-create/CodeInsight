#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include<vector>

using namespace std;
typedef long long ll;

ll ans,mx,sum,mn=1e8,cnt;


int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(ll i=0; i<n-1; i++){
		sum +=a[i];
	}
	if(a[n-1]<sum) cout<<"Yes";
	else cout<<"No";
}


