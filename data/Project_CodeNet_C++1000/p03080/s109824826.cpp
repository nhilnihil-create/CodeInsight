#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
	ll n;
	string s;
	cin>>n>>s;
	ll bc=0,rc=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='B')bc++;
		else rc++;
	}
	cout<<(rc>bc?"Yes":"No");
	return 0;
}
