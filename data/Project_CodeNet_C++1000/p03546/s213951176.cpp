#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
#define int ll
int dist[10][10];
int a[201][201];
int32_t main()
{
	#ifndef ONLINE_JUDGE
	freopen("in","r",stdin);
	freopen("out","w",stdout);
	#endif

	int h,w;
	cin>>h>>w;

	for(int i=0;i<=9;i++)
		for(int j=0;j<=9;j++)
			cin>>dist[i][j];

	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)cin>>a[i][j];


	for(int k=0;k<=9;k++)
		for(int j=0;j<=9;j++)
			for(int i=0;i<=9;i++)
				dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

	int ans=0;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			if(a[i][j]!=-1)
			ans+=dist[a[i][j]][1];
	cout<<ans;

	
}