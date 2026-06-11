#include <bits/stdc++.h>
#define int long long
using namespace std;

int ans=100000000;
void solve(int a,int b,int c){
	ans=min(ans,llabs(a-b)+llabs(c-b));
}

signed main(){
	int a,b,c; cin>>a>>b>>c;
	solve(a,b,c);
	solve(a,c,b);
	solve(b,a,c);
	solve(b,c,a);
	solve(c,b,a);
	solve(c,a,b);
	cout<<ans<<endl;
}