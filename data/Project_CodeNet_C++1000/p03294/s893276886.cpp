#include<bits/stdc++.h>
using namespace std;
#define ll long long int

#define MAXN 1000001	
ll spf[MAXN]; 


int main(){
		

	ll n;
	cin>>n;
	ll ar[n];
	
	for(int i=0;i<n;i++){
	 	cin>>ar[i];
	}
	
	ll ans = 0;
	for(int i=0;i<n;i++){
		ans+=(ar[i]-1);
	}	
	
	cout<<ans;

	
	
	return 0;
}
