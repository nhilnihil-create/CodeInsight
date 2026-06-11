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
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector<int> dot(n),h(n);
	if(s[0]=='#')h[0]=1;if(s[n-1]=='.')dot[n-1]=1;
	for(int i=1;i<n;i++)
	{
		h[i]=h[i-1]+(s[i]=='#');
	}
	
	for(int i=n-2;i>=0;i--)
		dot[i]=dot[i+1]+(s[i]=='.');
	
	int ans=min(h[n-1],dot[0]);
	for(int i=0;i<n-1;i++)ans=min(ans,h[i]+dot[i+1]);
	cout<<ans;
}