#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
	ll n,count=0;
	cin>>n;
	for(ll i=1;i*i<=n;i++){
		if(n%i==0){
			if(n/i-1>i) count+=n/i-1;
			else break;
		}
	}
	cout<<count<<endl;
	// your code goes here
	return 0;
}