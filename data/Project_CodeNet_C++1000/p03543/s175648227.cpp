#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	string s;
	cin>>s;
	if(s[0]==s[1] && s[1]==s[2]) cout<<"Yes";
	else if(s[1]==s[2] && s[2]==s[3]) cout<<"Yes";
	else cout<<"No";
	return 0;
}
