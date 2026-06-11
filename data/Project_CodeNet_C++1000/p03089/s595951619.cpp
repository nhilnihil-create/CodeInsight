#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <cmath>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <stack>

using namespace std;
typedef long long  ll;

const ll mod = 1000000007;

int main()
{
	ll N;
	cin >> N;
	vector<ll> a(N);
	for (ll i = 0; i < N; i++)
	{
		cin >> a[i];
	}
	bool flag = false;
	stack <ll> que;
	for (ll i = 0; i < N; i++)
	{
		for (ll j = a.size() - 1; j >= 0; j--)
		{
			if (a[j] == j + 1LL)
			{
				a.erase(a.begin() + j);
				que.push(j + 1LL);
				flag = true;
				break;
			}
		}
		if (!flag) {
			cout << -1 << endl;
			return 0;
		}
		flag = false;
	}
	while (!que.empty())
	{
		cout << que.top() << endl;
		que.pop();
	}
	return 0;
}