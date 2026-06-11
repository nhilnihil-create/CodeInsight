#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	int ans=0;
	rep(i,k) ans+=s[i]-'0';
	int n=stoi(s);
	if(n%ans==0) cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
}
