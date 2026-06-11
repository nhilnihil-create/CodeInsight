#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s,t; cin>>s>>t;
	if(s==t) {cout<<"Yes"<<endl; return 0;}
	
	int k=s.size();
	rep(i,k){
		string r=s.substr(k-1,1);
		s.erase(k-1,1);
		r+=s.substr(0,k);
		s=r;
		if(s==t) {cout<<"Yes"<<endl; return 0;}
	}
	cout<<"No"<<endl;
}