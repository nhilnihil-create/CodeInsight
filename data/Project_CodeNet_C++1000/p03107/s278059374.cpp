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
	string s;
	cin >> s;

	int min1 = 0;
	int min0 = 0;

	rep(i, s.size())
	{
		if (s[i] == '0')
			min1++;
		else
			min0++;
	}
	cout << min(min1, min0) * 2 << endl;
	return (0);
}
