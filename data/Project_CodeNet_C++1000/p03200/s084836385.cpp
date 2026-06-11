#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){

	string s;
	cin>>s;
	
	ll ans=0;
	ll c=0;
	for(int i=s.size()-1;i>=0;i--){
		if(s[i]=='B'){
			ans+=(s.size()-1LL-c)-i;
			c++;
		}
		
	}
	cout<<ans<<"\n";




}
