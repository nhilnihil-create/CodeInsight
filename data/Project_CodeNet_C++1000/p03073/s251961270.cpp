#include<bits/stdc++.h>
using namespace std;
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
	fastio
	string s;
	cin>>s;
	int cnt1=0;
	for(int i=0;i<s.size();++i){
		if(i&1 && s[i]!='0') ++cnt1;
		else if(i%2==0 && s[i]!='1') ++cnt1; 
	}
	int cnt2=0;
	for(int i=0;i<s.size();++i){
		if(i&1 && s[i]!='1') ++cnt2;
		else if(i%2==0 && s[i]!='0') ++cnt2;
 	}
 	//cout<<cnt1<<" "<<cnt2<<'\n';
 	cout<<min(cnt1,cnt2);
	return 0;
}