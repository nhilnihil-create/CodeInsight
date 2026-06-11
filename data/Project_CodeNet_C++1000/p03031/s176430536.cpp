#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;


int n, m; 

vector<int> p;

int main() {
	cin >> n >> m;
	Graph v(m);
	vector<int> p(m);

	for (int i = 0; i < m; i++)
	{
		int k;
		cin >> k;
		for (int j = 0; j < k; j++)
		{
			int x;
			cin >> x;
			v[i].push_back(x - 1);
		}
	}

	rep(i,m) cin >> p.at(i);

	int ans = 0;
	
	for (int i = 0; i < (1<<n); i++)
	{
		bool ok = 1;
		for (int j = 0; j < m; j++)
		{
			int cnt = 0;
			for (auto t : v.at(j)) {
				if ((1 << t) & i)cnt++;
			}
			if (cnt % 2 != p[j])ok = 0;
		}
		ans += ok;
	}
	cout << ans << endl;
}