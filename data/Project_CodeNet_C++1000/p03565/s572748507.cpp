#include<bits/stdc++.h>
using namespace std;
string ans="~";
int main(){
	string s;
	cin>>s;
	string t;
	cin>>t;
	if(s.size()<t.size()){
		cout<<"UNRESTORABLE";
		return 0;
	}
	for(int i=0;i<=s.size()-t.size();i++){
		bool flag=1;
		for(int j=0;j<t.size();j++){
			if(s[i+j]!=t[j]&&s[i+j]!='?'){
				flag=0;
				break;
			}
		}
		if(flag){ 
			string s2=s;
			for(int j=0;j<t.size();j++)s2[i+j]=t[j];
			for(int j=0;j<s.size();j++)if(s2[j]=='?')s2[j]='a';
			ans=min(ans,s2);
		}
	}
	if(ans=="~"){
		cout<<"UNRESTORABLE";
		return 0; 
	}
	cout<<ans;
	return 0;
}