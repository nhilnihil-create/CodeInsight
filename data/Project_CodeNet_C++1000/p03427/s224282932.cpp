#include<bits/stdc++.h>
#define all(v) v.begin(),v.end()
using namespace std;
int main(){
	cin.tie(0);
    ios::sync_with_stdio(false);
	string  s;
	cin>>s;
	int ans=0;
	bool a=false;
	for(int i=1;i<s.size();i++){
		if(s[i]!='9'){
			a=true;
		}
		ans+=9;
	}
	if(a){
		ans+=s[0]-'1';
	}
	else{
		ans+=s[0]-'0';
	}
	
	cout<<ans<<endl;
	return(0);
}