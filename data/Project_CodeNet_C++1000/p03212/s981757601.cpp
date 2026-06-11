#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define vv(T) std::vector<std::vector<T>>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;

ll n;

void	dfs(ll tmp, char use, ll *cnt)
{
	if (tmp > n)
		return ;
	if (use == 7)
		++(*cnt);
	dfs(tmp * 10 + 7, use | 0b001, cnt);
	dfs(tmp * 10 + 5, use | 0b010, cnt);
	dfs(tmp * 10 + 3, use | 0b100, cnt);
}

int		main(void)
{
	cin >> n;
	ll ans = 0;
	dfs(0, 0, &ans);
	cout << ans << endl;
}

