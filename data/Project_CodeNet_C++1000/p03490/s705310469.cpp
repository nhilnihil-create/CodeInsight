// In the name of God

#include <bits/stdc++.h>

using namespace std;

const int MAX = 16005;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string s;
	cin >> s;
	int x, y;	
	cin >> x >> y;
	vector<int> comps;
	int len = 0;
	for(int i = 0; i < s.length(); i++) {
		if(s[i] == 'T') {
			comps.push_back(len);
			len = 0;
		}
		else len++;
	}
	comps.push_back(len);
	x -= comps[0];
	vector<int> xs, ys;
	for(int i = 1; i < comps.size(); i++) {
		if(i & 1) ys.push_back(comps[i]);
		else xs.push_back(comps[i]);
	}
	auto solve = [](vector<int> &items, int goal) {
		bitset<MAX * 2 + 5> bs(0);
		bs[MAX] = 1;
		for(int x : items) {
			bitset<MAX * 2 + 5> now(0);
			now |= (bs << x);
			now |= (bs >> x);
			bs = now;
		}
		return bs[goal + MAX];
	};
	if(solve(xs, x) && solve(ys, y)) cout << "Yes";
	else cout << "No";
	return 0;
}
