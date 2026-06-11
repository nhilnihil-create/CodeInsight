#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> mp;
#define inf 1e9


int main(){
	string s;
	cin>>s;
	if(s.size()==2)cout<<s<<endl;
	else {
		for(int i=s.size()-1;i>=0;i--)cout<<s[i];
		cout<<endl;
	}


	return 0;
}
