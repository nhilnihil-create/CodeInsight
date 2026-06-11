#include <bits/stdc++.h>

using namespace std;

map<int,int> mp;
int n,seq[200050];

bool chk(int mid)
{
	mp.clear();
	for(int i = 2;i <= n; ++ i)
		if(seq[i] <= seq[i - 1])
		{
			while(!mp.empty())
			{
				if((mp.rbegin() -> first) > seq[i]) mp.erase(mp.rbegin() -> first);
				else break;
			}
			int ps = seq[i];
			while(ps && mp[ps] + 1 == mid) mp.erase(ps), ps --;
			if(!ps) return false;
			mp[ps] ++;
		}
	return true;
}

int main()
{
	scanf("%d",&n);
	for(int i = 1;i <= n; ++ i) scanf("%d",&seq[i]);
	int flg = 0;
	for(int i = 2;i <= n; ++ i)
		if(seq[i] <= seq[i - 1])
		{
			flg = 1;break;
		}
	if(!flg)
	{
		printf("1\n");
		return 0;
	}
	int l = 2,r = n,ans;
	while(l <= r)
	{
		int mid = (l + r) >> 1;
		if(chk(mid)) r = mid - 1,ans = mid;
		else l = mid + 1;
	}
	printf("%d\n",ans);
}