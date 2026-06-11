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
	char c=s[0];
	int ans=1;
	for(int i=1;i<4;++i){
		if(s[i]==c) ++ans;
		else{
			c=s[i];
			ans=1;
		}
		if(ans==3){
			cout<<"Yes";
			return 0;
		}
	}
	cout<<"No";
	return 0;
}
