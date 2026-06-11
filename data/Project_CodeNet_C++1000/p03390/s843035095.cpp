#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string>
#include <cmath>
#define ll long long

using namespace std;

ll q,a,b; 

int main(){
	
	cin>>q;
	while(q){
		cin>>a>>b;
		if(a==1&&b==1){
			cout<<0<<endl;
			q--;continue;
		}
		ll min1=min(a,b);
		ll x=sqrt(a*b)+100;
		while(x*x>(a*b)-1)x--;
		ll ans=2*x;
		if(x>=min1)ans--;
		if(x==((a*b)-1)/x)ans--;
		cout<<ans<<endl;

		q--;
	}


	return 0;
}

