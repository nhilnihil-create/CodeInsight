#include<algorithm>
#include<cstdio>
#include<vector>
#define ll long long
using namespace std;
vector<pair<ll, ll>> vt;
vector<pair<ll, ll>>vt1;
int main()
{
	ll n;
	scanf("%lld", &n);
	ll sum = 0;
	ll gap = 1234567890;
	for (int i = 0; i < n; i++)
	{
		ll q, w;
		scanf("%lld %lld", &q, &w);
		sum += q;
		if (q < w)
			vt.push_back({ q,w });
		else {
			if (q > w)
				gap = min(gap, w);
			vt1.push_back({ w,q });
		}
	}
	if (vt1.size() == n)
	{
		puts("0");
		return 0;
	}
	sum -= gap;
	printf("%lld\n", sum);
}
