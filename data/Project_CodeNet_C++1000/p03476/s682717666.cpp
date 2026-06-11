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


bool check(ll n){
	for(ll i=2; i*i<=n; i++){
		if(n%i==0) return false;
	}
	return true;
}

ll b[1000],idx,c[100001];
int main(){
	for(ll i=3; i<=100000; i+=2){
		ll flag=(i+1)/2;
		if(check(i)==true && check(flag)==true){
			b[idx++]=i;
		}
	}
	for(ll i=0; i<idx; i++){
		ll flag=b[i];
		c[flag]++;
	}
	for(ll i=3; i<100001; i++){
		if(c[i]==1) cnt++;
		c[i]=cnt;
	}
	ll q;
	cin>>q;
	for(ll i=0; i<q; i++){
		ll l,r;
		cin>>l>>r;
		cout<<c[r]-c[l-1]<<endl;
	}
}
