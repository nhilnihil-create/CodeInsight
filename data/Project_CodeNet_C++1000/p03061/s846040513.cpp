#include <iostream>
#include <algorithm>
#include <string>
#include <math.h>
#include <cstdint>
#include <sstream>
#include <map>
#include <cstring>
#include <vector>
#include <queue>
#include <iomanip>
#include <stack>
#include <unordered_set>

using namespace std;
typedef long long ll;

ll ans, mx, sum, mn = 1e14, cnt;



ll gcd(ll a,ll b){ 
    if (a == 0) 
        return b; 
    return gcd(b % a, a); 
} 

ll b[10000000],c[1000000];
int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0; i<n; i++){
		cin>>a[i];
	}
	ll first=a[0];
	b[0]=a[0];
	for(ll i=1; i<n; i++){
		first =gcd(first,a[i]);
		b[i]=first;
		//mx=max(mx,first);
	}
	ll sec=a[n-1];
	c[n-1]=a[n-1];
	for(ll i=n-2; i>=0; i--){
		sec=gcd(sec,a[i]);
		c[i]=sec;
		//mx=max(mx,sec);
	}
	if(n==2){
		ll j= max(a[0],a[1]);
		ll f=gcd(a[0],a[1]);
		cout<<max(f,j);
		return 0;
	}
	
	
	for(ll i=1; i<n; i++){
		
		ll j=gcd(b[i-1],c[i+1]);
		mx=max(mx,j);
	}
	ll p= max(mx,c[1]);
	ll v=max(p,b[n-2]);
	cout<<v;
}

