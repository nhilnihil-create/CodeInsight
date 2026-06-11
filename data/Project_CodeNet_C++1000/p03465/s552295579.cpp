#pragma GCC optimize(3)
#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll FFF=2000+5;

ll n,a;
ll now;

bitset<FFF*FFF> bs;

int main()
{
	//if(fopen(".in", "r"))
	//{
	//	freopen(".in", "r", stdin);
	//	freopen(".out", "w", stdout);
	//}
	ios::sync_with_stdio(false);
	cin>>n;
	bs[0]=1;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		bs|=bs<<a;
		now+=a;
	}
	for(int i=(now+1)/2;i<=now;++i)
	{
		if(bs[i]!=0)
		{
			cout<<i<<endl;
			return 0;
		}
	}
}