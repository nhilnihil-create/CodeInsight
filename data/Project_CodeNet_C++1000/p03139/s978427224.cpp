#include<bits/stdc++.h>
using namespace std;

using ll=long long; 

void solve(){
	int n,x,y;
	cin>>n>>x>>y;
	cout<<min(x,y)<<" "<<max(0, x+y-n)<<endl;
}

signed main(){
	//while(1)
	solve();
}