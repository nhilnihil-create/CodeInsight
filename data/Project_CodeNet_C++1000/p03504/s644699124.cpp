#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
const int N=1e5+4;
int s[N],t[N],c[N];
int tt[2*N],rec[2*N];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif
	int n,C;
	cin>>n>>C;
	for(int i=0;i<n;i++)
	{
		cin>>s[i]>>t[i]>>c[i];
		s[i]=2*s[i]-1;
		t[i]=2*t[i];
	}

	for(int i=1;i<=C;i++)
	{
		for(int j=0;j<2*N;j++)tt[j]=0;
		for(int j=0;j<n;j++)
			if(c[j]==i){tt[s[j]]++;tt[t[j]]--;}

		for(int j=1;j<2*N;j++)tt[j]+=tt[j-1];

		for(int j=0;j<2*N;j++)if(tt[j])rec[j]++;
	}
	int mx=0;
	for(int i=0;i<2*N;i++)mx=max(rec[i],mx);

	cout<<mx;



	
}