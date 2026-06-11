#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;

signed main(){
	int n, C;
	scanf("%d %d", &n, &C);
	vector<int> s(n), t(n), c(n);
	vector<vector<P> > data(C);
	for(int i = 0; i < n; i++){
		scanf("%d %d %d", &s[i], &t[i], &c[i]);
		data[c[i] - 1].push_back(P(s[i], t[i]));
	}
	
	for(int i = 0; i < C; i++){
		sort(data[i].begin(), data[i].end());
		for(int j = 1; j < data[i].size(); j++){
			if(data[i][j - 1].second == data[i][j].first) data[i][j].first++;
		}
	}

	vector<int> num(100010, 0);
	for(int i = 0; i < C; i++){
		for(int j = 0; j < data[i].size(); j++){
			num[data[i][j].first]++;
			num[data[i][j].second + 1]--;
		}
	}

	for(int i = 1; i < num.size(); i++){
		num[i] += num[i - 1];
	}

	int ans = *max_element(num.begin(), num.end());
	cout << ans << endl;
}