#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size(),cnt=15-n;
	for(int i=0;i<n;++i)
		if(s[i]=='o') ++cnt;
	if(cnt>=8) cout<<"YES";
	else cout<<"NO";
	return 0; 
}