#include <bits/stdc++.h>
#define mp make_pair
#define eb emplace_back
#define fi first
#define se second
using namespace std;
using cd = complex <double>;
 
typedef pair <int, int> pii;
 
const long long INF = 1e15;
const int mod = 998244353;//1000000007;
const double Pi = acos(-1);
 
void Fastio()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int n, k;
long long R[1005];
vector <long long> Temp;

int main()
{
	Temp.eb(0);
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
	{
		int temp;
		cin >> R[i];
		R[i] += R[i - 1];
	}
	for(int i = 0; i <= n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			Temp.eb(R[j] - R[i]);
		}
	}
	long long ans = 0;
	for(int i = 50; i >= 0; i--)
	{
		int c = 0;
		for(auto x : Temp)
		{
			long r = x & ans;
			if(r == ans)
			{
				if(x & (1ll << i))
				{
					c++;
				}
			}
		}
		if(c >= k)
		{
			ans ^= (1ll << i);
		}
	}
	cout << ans;
}