#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll a,b,c;
	cin>>a>>b>>c;
	string s="";
	s+=(a+'0');
	s+=(b+'0');
	s+=(c+'0');
	sort(s.rbegin(),s.rend());
	
	ll ans=((s[0]-'0')*10)+(s[1]-'0');
	ll k=s[2]-'0';
	cout<<ans+k<<endl;
	
}