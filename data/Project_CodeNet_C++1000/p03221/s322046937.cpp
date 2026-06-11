#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
	int n, m; cin >> n >> m;
	vector<pair<int,int>> que(m), ans(m);
	map<pair<int,int>, int> sor;
	for(int i = 0; i < m; i++) {
		cin >> que[i].first >> que[i].second;
		ans[i] = que[i];
	}
	sort(que.begin(), que.end());
	for(int i = 1; i < m; i++) {
		if(que[i].first != que[i - 1].first) {
			sor[que[i]] = 0;
		}else {
			sor[que[i]] = sor[que[i - 1]] + 1;
		}
	}

	for(int i = 0; i < m; i++) {
		std::cout << std::setfill('0') << std::right << std::setw(6) << ans[i].first; // "0012"
		std::cout << std::setfill('0') << std::right << std::setw(6) << sor[ans[i]]+1 << endl;; // "0012"

	}

}