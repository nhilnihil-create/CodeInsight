#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i < (int)(n); i++)
using namespace std;
using P = pair<int, int>;
typedef long long ll;

int  main()
{
	string s; cin >> s;
	int ans = 753;
	rep(i, s.size() - 2)
		ans = min(abs(stoi(s.substr(i, 3)) - 753), ans);
	cout << ans << endl;
	return (0);
}