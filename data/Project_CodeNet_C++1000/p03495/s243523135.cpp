#include "bits/stdc++.h"

typedef long long ll;

const int MAX_SIZE = 2e5 + 5;

int freq[MAX_SIZE];

int main()
{
	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 0; i < n; ++i)
	{
		int temp;
		scanf("%d", &temp);
		++freq[temp];
	}
	std::vector<int> v;
	v.reserve(MAX_SIZE);
	for (int i = 0; i < MAX_SIZE; ++i)
	{
		if (freq[i])
		{
			v.push_back(freq[i]);
		}
	}
	std::sort(v.begin(), v.end());
	ll ans = 0;
	int end = v.size() - k;
	for (int i = 0; i < end; ++i)
	{
		ans += v[i];
	}
	printf("%lld\n", ans);
	return 0;
}