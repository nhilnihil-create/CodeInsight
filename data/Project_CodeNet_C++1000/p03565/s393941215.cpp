#include<bits/stdc++.h>
using namespace std;
int main(){
	string s,t,r;
	cin>>t>>s;
	bool g,f=0;
	for(int i=t.size()-s.size();i>=0;i--){
		r=t;g=1;
		for(int j=0;j<s.size();j++){
			if(!(t[i+j]=='?'||t[i+j]==s[j])){g=0;break;}
			r[i+j]=s[j];
		}
		if(g){
			for(int i=0;i<r.size();i++){if(r[i]=='?')cout<<'a';else cout<<r[i];}
			return 0;
		}
	}
	cout<<"UNRESTORABLE";
	return 0;
}