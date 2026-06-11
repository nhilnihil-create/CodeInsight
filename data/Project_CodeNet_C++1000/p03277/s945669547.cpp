#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <string.h>
#include <stack>
#define Endl endl
#define mp make_pair
#define rep(N) for(int i=0;i<N;i++)
#define repj(N) for(int j=0;j<N;j++)
#define ll long long 
#define pii pair<int,int>
#define pll pair<ll,ll>
#define For(I,N) for(int I=0;I<N;I++)
#define cinone(N) int N;cin>>N;
#define scanfone(N) int N;cin>>N;
#define cinng(N,M) int N[M];for(int yiuytvnm=0;yiuytvnm<M;yiuytvnm++) cin>>N[yiuytvnm];
#define scanfng(N,M) int N[M];for(int qrwuoiq=0;qrwuoiq<M;qrwuoiq++) scanf("%d",&N[qrwuoiq]);
#define over(A) {cout<<A<<endl;exit(0);}
#define all(A) A.begin(),A.end()
#define ceil(a,b) ((a-1)/b+1)
typedef unsigned long long ull;
const int inf=1039074182;
using namespace std;
int n;
int a[100005];
vector <int> vec;
int b[100005];
int sum[100005];
ll bit[400005];
int nn;

ll query(int x)
{
	ll res=0;
	while(x)
	{
//		cout<<x<<endl;
		res+=bit[x];
		x&=x-1;
	}
	return res;
}

void add(int x,int delta)
{
	while(x<=nn)
	{
		bit[x]+=delta;
		x+=x&-x;
	}
}

bool check(int x)
{
	for(int i=0;i<=400000;i++)
	{
		bit[i]=0;
	}
//	memset(sum,0,sizeof(bit));
//	bool debug=(x==30);
	for(int i=0;i<n;i++)
	{
		b[i]=(a[i]>=x?1:-1);
	}
//	for(int i=0;i<n;i++)
//	{
//		if(debug) cout<<b[i]<<' ';
//	}
//	if(debug) cout<<endl;
	sum[0]=b[0];
	for(int i=1;i<n;i++)
	{
		sum[i]=sum[i-1]+b[i];
	}
	ll res=0;
	for(int i=0;i<n;i++)
	{
		res+=(sum[i]>=0);
		sum[i]+=100000;
	}
	for(int i=0;i<n;i++)
	{
//		if(debug) cout<<query(sum[i])<<endl;
		res+=query(sum[i]);
		add(sum[i],1);
	}
//	for(int i=0;i<n;i++)
//	{
//		res+=(sum[i]>=0);
//		for(int j=i+1;j<n;j++)
//		{
//			if(sum[i]<=sum[j]) res++;
//		}
//	}
//	for(int i=0;i<n;i++)
//	{
//		if(debug) cout<<b[i]<<' ';
//	}
//	if(debug) cout<<endl;
//	for(int i=0;i<n;i++)
//	{
//		sum[i]+=100000;
//	}
//	ll res=0;
//	for(int i=0;i<n;i++)
//	{
////		if(debug) cout<</*query(131071)-*/query(sum[i])<<endl;
//		res+=query(131071)-query(sum[i]-1);
//		add(sum[i],1);
//	}
//	cout<<x<<' '<<res<<endl;
//	cout<<query(400000)<<endl;
//	cout<<x<<' '<<(res>=(ceil(n*(n+1)/2,2)))<<endl;
	return (res>=(ceil(1LL*n*(n+1)/2,2)));
}

int main()
{
//	freopen("input.txt","r",stdin);
//	ios_base::sync_with_stdio(false);
	cin>>n;
	nn=1;
	while(nn<n+100000)
	{
		nn<<=1;
	}
	for(int i=0;i<n;i++)
	{
		scanf("%d",a+i);
//		cin>>a[i];
		vec.push_back(a[i]);
	}
	sort(all(vec));
	vec.erase(unique(all(vec)),vec.end());
	int l=0,r=vec.size()-1,m,ans=3;
	while(l<=r)
	{
		m=l+r>>1;
		if(check(vec[m]))
		{
			ans=m;
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	cout<<vec[ans];
	return 0;
}