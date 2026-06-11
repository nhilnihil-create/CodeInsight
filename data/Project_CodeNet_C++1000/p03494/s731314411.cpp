#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
	int n;
	int ans = 1001001001;
	int cnt = 0;
	cin >> n;
	vector<int> vec(n);
	rep(i, n) cin >> vec[i];

	rep(i, n)
	{
		cnt = 0;
		while (vec[i] % 2 == 0)
		{
			cnt++;
			vec[i] /= 2;
		}
		ans = min(ans, cnt);
	}
	cout << ans << endl;
	return (0);
}
