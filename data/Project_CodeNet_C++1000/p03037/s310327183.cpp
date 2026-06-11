#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int n,m; cin>>n>>m;
	int mn=1, mx=n;
	rep(i,m){
		int l,r; cin>>l>>r;
		mn=max(mn,l);
		mx=min(mx,r);
	}
	if(mx-mn<0) cout<<0<<endl;
	else cout<<mx-mn+1<<endl;
}