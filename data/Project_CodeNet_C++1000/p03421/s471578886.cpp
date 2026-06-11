#include<bits/stdc++.h>
using namespace std;
int v[300005];

int main()
{
	long long a,b,n;
	scanf("%lld %lld %lld",&n,&a,&b);
	if(n > a*b || (a+b-1) > n)
	{
		puts("-1");
		return 0;
	}
	v[1] = b;
	for(int i = 2; i <= a; i++)
	{
		v[i] = 1;
	}
	int tot = a + b - 1;
	int idx = 2;
	while(tot < n)
	{
		while(v[idx] == b)
			idx++;
		v[idx]++;
		tot++;
	}
	vector<int>ans;
	long long val = 0;
	for(int i = 1; i <= a; i++)
	{
		for(int j = val+v[i]; j >= val + 1 ; j--)
		{
			ans.push_back(j);
		}
		val += v[i];
	}
	for(int i = 0; i < ans.size(); i++)
	{
		printf("%d%c",ans[i]," \n"[i == ans.size()-1]);
	}
	return 0;
}
