#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ll n,p,ans=1;
	cin>>n>>p;
	ll i=pow(p,1.0/n);
	for(i=i+1;i>=1;i--){
		if( (p%((ll)pow(i,n))) ==0){
			ans=i;
			break;
		}
	}
	cout<<ans;
	return 0; 
} 
 
