#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
bool vis[100005];
LL k;
deque<pair<LL, LL> > dq;
int main()
{
	cin >> k;
	dq.push_back(make_pair(1, 1));
	while(!dq.empty())
	{
		pair<LL, LL> x = dq.front(); dq.pop_front();
		if(!x.first) { cout << x.second << endl; return 0; }
		if(vis[x.first]) continue; vis[x.first] = true;
		dq.push_front(make_pair(x.first * 10 % k, x.second));
		dq.push_back(make_pair((x.first + 1) % k, x.second + 1));
	}
	return 0;
}