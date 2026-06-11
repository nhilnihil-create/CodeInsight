#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int L=-1,R=100001,l,r,n,m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>l>>r;
		L=max(L,l);
		R=min(R,r);
	}
	cout<<max(R-L+1,0);
    return 0;
}
