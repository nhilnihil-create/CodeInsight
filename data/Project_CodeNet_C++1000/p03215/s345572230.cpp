#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int MAX_N = 1005;
ll a[MAX_N];
bool use[MAX_N*MAX_N];
vector<ll> subs;

int main()
{
	int N,K;
	cin >> N >> K;
	rep(i,N)
	{
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i)
	{
		ll temp = 0;
		for (int j = i; j < N; ++j)
		{
			temp += a[j];
			subs.push_back(temp);
		}
	}

	/*
	rep(i,subs.size())
	{
		cout << subs[i] << " ";
	}
	*/

	ll ans = 0;
	rep(i,subs.size())
	{
		use[i] = true;
	}
	for(int i = 45; i >= 0; --i)
	{
		int cnt = 0;
		rep(j,subs.size())
		{
			if (use[j] && ((1ull << i) & subs[j])) cnt++;
		}
		if (cnt >= K)
		{
			ans += (1ull << i);
			//cout << ans << " ";
			rep(j,subs.size())
			{
				if (use[j] && !((1ull << i) & subs[j])) use[j] = false;
			}
		}
		//cout << i << " " << cnt << endl;
	}
	cout << ans << endl;
	return 0;
}