#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll 
int32_t main()
{
	
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n,z,w;
	cin>>n>>z>>w;
	vector<int> a(n);for(auto &i:a)cin>>i;

	if(n==1){cout<<abs(w-a[0]);return 0;}
	cout<<max(abs(a[n-1]-a[n-2]),abs(a[n-1]-w));

	

}