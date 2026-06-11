#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
	int n;
	cin >> n;
	vector<int> a(n);
	for(auto &i:a)cin >> i;
	sort(a.begin(),a.end());
	//a.erase(unique(a.begin(),a.end()),a.end());
	//for(auto i:a)cout<<i<<endl;
	int ans = 0;
	for(int BIT;BIT<(1<<23);BIT++)
	{
		int bit = BIT<<1;
		bit ++;
		int now = 24;
		int l = 1;
		for(int i = 1;i<24;i++)
		{
			if((bit>>i&1)==0)l ++;
			else
			{
				now = min(l,now);
				l=1;
			}
		}
		now = min(l,now);
		//cout<<now<<endl;
		bool flag = true;
		bit--;
		for(int i =0 ;i<n;i++)
		{
			if((bit>>a[i]&1))
			{
				bit -= 1<<a[i];
			}
			else if((bit>>(24-a[i])&1))
			{
				bit -= 1<<(24-a[i]);
			}
			else 
			{
				flag = false;
			}
		}
		if(flag)
		{
			//cout<<';'<<endl;

			ans = max(now,ans);
		}
	}
	cout<<ans<<endl;
}