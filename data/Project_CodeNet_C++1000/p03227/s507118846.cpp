#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	string sr=s;
	reverse(sr.begin(),sr.end());
	if(s.size()==2) cout<<s<<endl;
	else cout<<sr<<endl;
}