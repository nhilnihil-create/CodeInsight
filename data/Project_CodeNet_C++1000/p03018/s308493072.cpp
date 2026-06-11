#include <bits/stdc++.h>
#define rep(i,n) for ((i)=1;(i)<=(n);(i)++)
using namespace std;
int n,i,x;
string s,t;
long long ans;
int main(){
	cin>>s;
	for(i=0;i<s.size();i++){
		if(i<s.size()&&s[i]=='B'&&s[i+1]=='C'){
			t.push_back('D');
			i++;
		}
		else{
			t.push_back(s[i]);
		}
	}
	for(i=0;i<t.size();i++){
		if(t[i]=='A') x++;
		else if(t[i]=='D') ans+=x;
		else x=0;
	}
	cout<<ans;
	return 0;
}