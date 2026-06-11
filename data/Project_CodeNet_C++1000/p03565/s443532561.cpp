#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t;cin>>s>>t;
	if(t.size()>s.size()){cout<<"UNRESTORABLE";return 0;}
	string ans="";
	for(int i=0;i<=s.size()-t.size();++i){
		bool f=1;
		for(int j=0;j<t.size();++j){
			if(s[j+i]!='?'&&s[j+i]!=t[j]){f=0;break;}
		}
		if(f){
			string ss="";
			int j=0;
			for(;j<i;++j)ss+=(s[j]=='?'?'a':s[j]);
			for(;j<t.size()+i;++j)ss+=(t[j-i]);
			for(;j<s.size();++j)ss+=(s[j]=='?'?'a':s[j]);
			if(ans=="")ans=ss;
			else ans=min(ans,ss);
		}
	}
	if(ans!="")cout<<ans<<endl;
	else cout<<"UNRESTORABLE";
	return 0;
}
