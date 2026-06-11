#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	c--;
	int ans=b+1;
	ans+=min(a+b,c);
	cout<<ans<<endl;
}

signed main(){
	//while(1)
	solve();
}