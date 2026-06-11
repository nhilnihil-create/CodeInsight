#include <bits/stdc++.h>
using namespace std;
 
static const int INF = (1<<30)-1;
 
int main()
{
	string s;
	cin >> s;
	string now;
	int ans = INF;
	for (int i = 0; i < s.size() - 2; ++i)
	{
		now = s.substr(i, 3);
		ans = min(ans, abs(stoi(now)-753));
	}
	cout << ans << endl;
	return 0;
}