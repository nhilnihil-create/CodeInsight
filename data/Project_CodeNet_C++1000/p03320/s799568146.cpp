#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int s(ll x)
{
	int ret = 0;
	while(x) { ret += x % 10; x /= 10;}
	return ret;
}
vector<ll> ans = {1, 2, 3, 4, 5, 6, 7, 8};
int main()
{
	
	int K;
	scanf("%d", &K);
	
	for(int k = 1; k <= 13; ++k)
	{
		int prel = max(0, k - 2);
		int prer = k * 10 - 2;
		for(int pre = prel; pre <= prer; ++pre)
		{
			ll cur = pre;
			for(int i = 0; i < k; ++i)
				cur = cur * 10 + 9;
			ans.push_back(cur);
		}
	}
	for(int i = 0; i < ans.size(); ++i)
	{
		bool flag = 1;
		for(int j = i + 1; j < ans.size(); ++j)
			if(1.0 * ans[i] / s(ans[i]) > 1.0 * ans[j] / s(ans[j]))
			{
				flag = 0;
				break;
			}
		if(flag)
		{
			cout << ans[i] << endl;
			--K;
			if(!K)
				return 0;
		}
	}
	return 0;
}