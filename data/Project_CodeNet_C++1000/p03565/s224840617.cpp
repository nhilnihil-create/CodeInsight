#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using ll = long long;
int mod = 1000000000+7;

int main(){

	string s,t;
	cin>>s>>t;

	string ans="";
	int flag=-1;
	rep(i,s.size()){
		if(s[i]=='?' || s[i]==t[0]){
			int j=i+1;
			while(j<s.size() && j-i<t.size()){
				if(s[j]==t[j-i] || s[j]=='?')j++;
				else break;
			}
			if(j-i==t.size())flag=i;
		}
	}
	
	if(flag==-1)cout<<"UNRESTORABLE";
	else {
		rep(i,s.size()){
			if(i==flag){
				cout<<t;
				i+=t.size()-1;
			}
			else if(s[i]=='?')cout<<'a';
			else cout<<s[i];
		}
	}
	cout<<endl;

	return 0;
}
