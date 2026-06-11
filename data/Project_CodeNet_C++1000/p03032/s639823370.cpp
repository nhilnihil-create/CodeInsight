#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n,k;
	cin >> n >> k;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	ll ans = 0;
	for(int i = 1;i<=min(k,n);i++)//kこ取り出す時
	{
		for(int r = 0;r<=i;r++)//右からr個取り出す
		{
			ll sum = 0;
			vector<ll> now;
			for(int j =0;j<r;j++)
			{
				now.push_back(a[j]);
			}
			for(int j = 0;j<i-r;j++)
			{
				now.push_back(a[n-1-j]);
			}
			int s = k-i;
			sort(now.begin(),now.end());
			//if(i==3){//for(auto i:now)cout<<i<<' ';cout<<endl;}
			for(int j = 0;j<now.size();j++)
			{
				if(j<s)
				{
					if(now[j]>0)sum += now[j];
				}
				else
				{
					sum += now[j];
				}
			}
			ans = max(sum,ans);
			//if(i==k)cout<<sum<<endl;
		}
	}
	cout<<ans<<endl;
}