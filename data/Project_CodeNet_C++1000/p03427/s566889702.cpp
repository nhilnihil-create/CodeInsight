#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using ll = long long;
using vpii = vector<pair<int, int>>;
using vpll = vector<pair<ll, ll>>;
// ceil() 切り上げ, floor() 切り捨て
// next_permutation(all(x))

int		main(void)
{
	string N;
	cin >> N;
	int len = N.size();
	int ans;
	int i = 1;
	while (i < len && N[i] == '9')
		i++;
	if (i == len)
		ans = 9*(len-1) + N[0]-'0';
	else if (len == 1)
		ans = N[0]-'0';
	else if (N[0] == '1' && N[len-1] != '9')
		ans = 9*(len-1);
	else
		ans = 9*(len-1) + N[0]-'0'-1;
	cout << ans << endl;
}

