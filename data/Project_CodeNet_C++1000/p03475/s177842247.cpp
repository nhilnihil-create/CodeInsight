#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int C[501],F[501],S[501];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int n;cin>>n;
	for(int i=0;i<n-1;i++)
		cin>>C[i]>>S[i]>>F[i];

	for(int i=0;i<n;i++)
	{
		int t=0;
		for(int j=i;j<n-1;j++)
		{
			if(t<S[j])t=S[j];
			else if(t%F[j]!=0)t=t+F[j]-t%F[j];
			t+=C[j];
		}
		cout<<t<<"\n";
	}




	
}