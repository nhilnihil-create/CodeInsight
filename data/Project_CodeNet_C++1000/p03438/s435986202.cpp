#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1e9+7,MAX = 1e5;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n),b(n);
	for(int i = 0;i<n;i++)cin >> a[i];
	for(int i = 0;i<n;i++)cin >> b[i];

	//sort(a.begin(),a.end());
	//sort(b.begin(),b.end());
	/*
	5
3 1. 4 1 5
2 7. 1 8 2

3 7 4 7 5
3 7 3 9 3
	*/
	ll sum[2]={};
	for(int i = 0;i<n;i++)
	{
		sum[0] += a[i];
		sum[1] += b[i];
	}
	ll da = sum[1]-sum[0];//足せる回数
	ll db = da;

	for (int i = 0; i < n; ++i)
	{
		if(b[i]-a[i]>0)
		{
			ll d = b[i] - a[i];
			if(d<=0)continue;
			d = (d+1)/2;
			a[i] += d*2;
			da -= d;
		}
	}
	for(int i = 0;i<n;i++)
	{
		ll d = a[i]-b[i];
		b[i] = a[i];
		db -= d;
	}
	//for(int i = 0 ;i<n;++i){cout<<a[i]<<';'<<b[i]<<endl;}cout<<da<<';'<<db<<endl;
	if(da>=0&&db>=0&&da*2==db)
	{
		cout<<"Yes"<<endl;
	}
	else
	{
		cout<<"No"<<endl;
	}
	


	return 0;
}