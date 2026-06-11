#include<bits/stdc++.h>
using namespace std;

using ll=long long;

void solve(){
	int a,b,c;
	cin>>a>>b>>c;
	if((a>=c && c>=b) || (b>=c && c>=a)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
}

signed main(){
	//while(1)
	solve();
}