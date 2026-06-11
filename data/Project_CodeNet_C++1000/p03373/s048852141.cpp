#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
	int a,b,c;cin>>a>>b>>c;
	int x,y;cin>>x>>y;
	int ans = 1e18;
	for(int k=0;k<(int)1e6;k++){
		int cost = c*k+max((int)0,(x-(k/2)))*a+max((int)0,(y-(k/2)))*b;
		ans = min(ans,cost);
	}
	cout<<ans<<endl;
}