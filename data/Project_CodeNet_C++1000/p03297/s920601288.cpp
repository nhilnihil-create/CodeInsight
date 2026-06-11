#include<bits/stdc++.h>
using namespace std; 

#define inf 2000000009
#define ff first 
#define ss second 
#define ll long long

void pt(int i){
	cout<<((i==1)? "Yes":"No")<<endl; return; 
} 

int main(){
	int t; cin>>t; 
	while(t--){
		ll a,b,c,d; 
		cin>>a>>b>>c>>d; 
		if(b>a || d<b){
			pt(0); continue; 
		}
		else if(c>=b-1){
			pt(1); continue; 
		}
		a%=b; 
		d%=b; 
		ll g=__gcd(d,b); 
		if(c<b-g+a%g){
			pt(0); 
		}
		else {
			pt(1); 
		}

	}

}