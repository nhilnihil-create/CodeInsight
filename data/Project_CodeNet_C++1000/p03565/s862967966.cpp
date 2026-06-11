#include<bits/stdc++.h>
#define ll long long
#define all(a) a.begin(),a.end()
#define sz(a) a.size()
#define re return 
#define MP make_pair
#define pb push_back
#define pii pair<int,int>
#define se second
#define fi first
using namespace std;
string s,t;
string ans="~";
bool check(string a,string b){
	for(int i=0;i<sz(a);i++) if(b[i]!='?'&&b[i]!=a[i]) re 0;
	re 1;
}
signed main(){
	ios_base::sync_with_stdio(0);
	cin>>s>>t;
	for(int i=0;i+sz(t)<=sz(s);i++){
		string u=s.substr(i,sz(t));
		//cout<<u<<"\n";
		if(check(t,u)){
			string now=s;
			for(int j=0;j<sz(t);j++) now[i+j]=t[j];
			for(int j=0;j<sz(s);j++) if(now[j]=='?') now[j]='a';
			ans=min(ans,now);
		}
	}
	if(ans=="~") cout<<"UNRESTORABLE";
	else cout<<ans;
	re 0;
}