#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[214514];
int main(){
	ll n,q;
	string s;
	cin>>n>>q>>s;
	s="B"+s;
	for(int i=1;i<=n;i++){
		cnt[i]+=cnt[i-1];
		if(s.substr(i-1,2)=="AC")cnt[i]++;
	}
	while(q--){
		ll l,r;
		cin>>l>>r;
		if(s[l]=='C'&&s[l-1]=='A')cout<<cnt[r]-cnt[l-1]-1<<endl;
		else cout<<cnt[r]-cnt[l-1]<<endl;
	}
	return 0;
}
