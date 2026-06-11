#include"bits/stdc++.h"
using namespace std;
const int N=2e5+4;
int q[N];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;cin>>x;
		q[x]=i;
	}

	int k=1;
	int cur=1;
	for(int i=2;i<=n;i++)
	{
		if(q[i]>q[i-1])cur++;
		else cur=1;
		k=max(k,cur);
	}
	cout<<n-k;

}
