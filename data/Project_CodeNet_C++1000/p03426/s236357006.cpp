#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int h,w,d;
	cin >> h >> w >> d;
	vector<pair<int,int>> p(h*w);
	for(int i =0 ;i<h;i++)
	{
		for(int j = 0;j<w;j++)
		{
			int a;
			cin >> a;
			a--;
			p[a] = make_pair(i,j);
		}
	}

	vector<ll> sum(h*w+d+d);

	for(int i = 0;i<d;i++)
	{
		for(int j = i;j+d<h*w;j+=d)
		{
			sum[j+d] = sum[j] + abs(p[j+d].first-p[j].first)+abs(p[j+d].second-p[j].second);
		}
	}
	//cout<<sum.size()<<endl;
	int q;
	cin >> q;
	while(q--)
	{
		int l,r;
		cin >> l >>r ;
		l--;
		r--;
		cout<<sum[r]-sum[l]<<endl;
	}
	for(int i = 1;i<h*w+d;i+=d)
	{
		//cout<<sum[i]<<endl;
	}

}