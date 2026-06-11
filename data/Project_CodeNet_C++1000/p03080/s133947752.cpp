#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll M=1e5;
int main()
{
	ll n;cin>>n;
	string s;
	cin>>s;
	ll len=s.length();
	ll r=0,b=0;
	for(ll i=0;i<len;i++){
		if(s[i]=='R') r++;
		else b++;
	}
	
	if(r>b){
		cout<<"Yes"<<endl;
	}
	else{
		cout<<"No"<<endl;
	}
}