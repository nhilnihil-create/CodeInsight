#include<bits/stdc++.h>
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
    cin.tie(0);
	int ans=0,v[21],c,n;
	cin>>n;
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++){
		cin>>c;
		ans+=max(0,v[i]-c);
	}
	cout<<ans<<endl;
    return 0;
}
