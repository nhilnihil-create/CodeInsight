#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int n;
vector<ll> vt;
ll ch[16];
ll x;
int main()
{
	ch[0] = 1;
	for (int i = 1; i <= 14; i++)
		ch[i] = ch[i - 1] * 10;
	for (int i = 1; i < 10; i++)
		vt.push_back(i);
	for (int i = 1; i <= 14; i++)
	{
		for (int xx = 1; xx <= 9; xx++) {
			ll sum = ch[i]*xx;
			ll Ssum = xx;
			for (int y = 0; y < i; y++)
			{
				for (int z = 0; z < 9; z++)
				{
					if (sum <= Ssum*ch[y]) {
						vt.push_back(sum);
					}
					sum += ch[y];
					Ssum++;
				}
				if (sum <= Ssum*ch[y+1]) {
					vt.push_back(sum);
				}
			}
		}
	}
	sort(vt.begin(), vt.end());
	vt.erase(unique(vt.begin(), vt.end()), vt.end());
	scanf("%lld", &x);
	for (int i = 0; i < x; i++)
		printf("%lld\n", vt[i]);
}