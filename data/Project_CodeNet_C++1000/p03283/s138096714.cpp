#include<bits/stdc++.h>
using namespace std;
const int MAX = 500 + 5;
int a[MAX][MAX],n,m,q; 
int main()
{
	cin>>n>>m>>q;
	int maxx = -1,l,r;
	while(m--) {
		cin>>l>>r;
		maxx = max(maxx,r);
		a[l][r]++;
	}
	for(int i=1;i<=maxx;i++){
		for(int j=1;j<=maxx;j++){
			a[i][j]+=a[i][j-1];
		}
	}
		while(q--) {
		long long ans = 0;
		cin>>l>>r;
		for(int i = l; i<=r; i++) {
			ans += a[i][r];
		}
		cout<<ans<<endl;
	}
	
 
	return 0 ;


}