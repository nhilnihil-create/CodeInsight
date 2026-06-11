#include<bits/stdc++.h>
using namespace std;
int n,h,w;
int ans;
int main(){
	cin>>n>>h>>w;
	for(int i=1;i<=n;i++){
		int x,y; cin>>x>>y;
		if(x>=h&&y>=w) ans++;
	}
	cout<<ans<<endl;
	return 0;
}