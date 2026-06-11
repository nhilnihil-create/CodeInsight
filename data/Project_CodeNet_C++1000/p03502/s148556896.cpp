#include <bits/stdc++.h>

#define ll long long 
#define sz(x) (int)x.size()

using namespace std;

int f(ll n){
	int res=0;
	while(n){
		res+=n%10;
		n/=10;
	}
	return res;
}

int main(){
	ll n;
	cin>>n;
	cout<<(n%f(n)?"No":"Yes");
	
	
}