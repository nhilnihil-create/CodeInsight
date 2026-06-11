#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	ll h, w;
	cin >> h >> w;
	ll bc = 0;
	vector<vector<int>>s(h+2, vector<int>(w+2));
	for (int i = 0; i < h+2; i++) {
		if (i == 0 || i == h + 1) {
			for (int j = 0; j < w + 2; j++)s.at(i).at(j) = -1;
		}
		else {
			for (int j = 0; j < w + 2; j++) {
				if (j == 0 || j == w + 1)s.at(i).at(j) = -1;
				else {
					char x;
					cin >> x;
					if (x == '#') {
						s.at(i).at(j) = -1;
						bc++;
					}
					else s.at(i).at(j) = 100000;
				}
			}
		}
		
	}
	s.at(1).at(1) = 0;
	//多分bfs
	queue<pair<int,int>>search;
	search.push({ 1,1 });
	while (search.size() > 0) {
		pair<int,int> a = search.front();
		if (s.at(a.first - 1).at(a.second) > s.at(a.first).at(a.second) + 1) {
			s.at(a.first - 1).at(a.second) = s.at(a.first).at(a.second) + 1;
			search.push({ a.first - 1,a.second });
		}
		if (s.at(a.first + 1).at(a.second) > s.at(a.first).at(a.second) + 1) {
			s.at(a.first + 1).at(a.second) = s.at(a.first).at(a.second) + 1;
			search.push({ a.first + 1,a.second });
		}
		if (s.at(a.first).at(a.second - 1) > s.at(a.first).at(a.second) + 1) {
			s.at(a.first).at(a.second - 1) = s.at(a.first).at(a.second) + 1;
			search.push({ a.first,a.second - 1});
		}
		if (s.at(a.first).at(a.second + 1) > s.at(a.first).at(a.second) + 1) {
			s.at(a.first).at(a.second + 1) = s.at(a.first).at(a.second) + 1;
			search.push({ a.first,a.second + 1});
		}
		search.pop();
	}
	if (s.at(h).at(w) == 100000) {
		cout << -1 << endl;
		return 0;
	}
	ll ans = h * w - s.at(h).at(w) - bc - 1;
	cout << ans << endl;
}