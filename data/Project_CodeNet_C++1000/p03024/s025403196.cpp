#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	string s; cin>>s;
	int k=s.size();
	int cnt=0;
	rep(i,k){
		if(s[i]=='x') cnt++;
	}
	if(k>=8&&cnt>7) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
}