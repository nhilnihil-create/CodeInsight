#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int32_t main()
{
	#ifndef ONLINE_JUDGE
		freopen("in","r",stdin);
		freopen("out","w", stdout);
	#endif
	int n;
	cin>>n;
	if(n==0){cout<<0;return 0;}
	vector<int> ans;int rem;
	while(n)
	{
		rem=(n%(-2));
		if(!rem)ans.push_back(0);
		else
		{
			n--;
			ans.push_back(1);
		}
		n/=-2;
	}
	reverse(ans.begin(),ans.end());
	for(auto i:ans)cout<<i;

}