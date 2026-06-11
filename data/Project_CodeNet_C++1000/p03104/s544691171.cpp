#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
ll findXOR(ll n) 
{
	if(n==-1)	return 0; 
	int mod = n % 4;
	if(mod==0) 	return n;
	if(mod==1) 	return 1;
	if(mod==2) 	return n+1; 
	if(mod==3) 	return 0; 
}
ll findXOR(ll l,ll r) { return(findXOR(l-1)^findXOR(r)); }
int main() 
{
	ll l,r; 
	cin>>l>>r;
	cout<<findXOR(l,r); 
} 
