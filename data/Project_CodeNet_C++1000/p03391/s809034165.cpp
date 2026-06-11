#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	int n;cin>>n;
	ll ans=0;
	ll mn=1e9;
	bool is=true;
	for(int i=1;i<=n;i++){
		ll u,v;cin>>u>>v;
		ans+=u;
		if(v<u){
			mn=min(mn,v);
		}
		if(u!=v){
			is=false;
		}
	}
	if(is)cout<<0;
	else cout<<ans-mn;
	return 0;
}