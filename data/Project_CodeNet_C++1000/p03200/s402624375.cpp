#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	string s;cin>>s;
	ll cnt=0;
	ll ans=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='B'){
			cnt++;
		}else{
			ans+=cnt;
		}
	}
	cout<<ans;
}