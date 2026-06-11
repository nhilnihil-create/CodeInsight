#include<bits/stdc++.h>
using namespace std;
#define il inline
#define ll long long
#define no {cout<<"UNRESTORABLE";return 0;}
il int in(){
	int s=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')return -in();c=getchar();}
	while(c>='0'&&c<='9'){s=(s<<1)+(s<<3)+(c^48);c=getchar();}
	return s;
}
int main(){
	string s,t;cin>>s>>t;
	if(t.size()>s.size())no;
	string ans="";
	for(int _=0;_<=s.size()-t.size();++_){
		bool f=1;
		for(int __=0;__<t.size();++__){
//			cout<<s[__+_]<<' '<<t[__]<<endl;??p
			if(s[__+_]!='?'&&s[__+_]!=t[__]){f=0;break;}
		}
		if(f){
			string ss="";
			int __=0;
			for(;__<_;++__)ss+=(s[__]=='?'?'a':s[__]);
			for(;__<t.size()+_;++__)ss+=(t[__-_]);
			for(;__<s.size();++__)ss+=(s[__]=='?'?'a':s[__]);
			if(ans=="")ans=ss;
			else ans=min(ans,ss);
		}
//		cout<<endl;
	}
	if(ans!=""){cout<<ans<<endl;return 0;}
	no;
	return 0;
}
