#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int xt, yt;
vector<int> x, y;
bool fx = 1;
string s;

bool check(vector<int> mv, int t) {
	vector<int> pos;
	pos.push_back(0);
	for (int i = 0; i < mv.size(); i++) {
		vector<int> nw;
		for (int j = 0; j < pos.size(); j++) {
			nw.push_back(pos[j] + mv[i]);
			nw.push_back(pos[j] - mv[i]);
		}
		sort(nw.begin(), nw.end());
		nw.resize(unique(nw.begin(), nw.end()) - nw.begin());
		pos = nw;
	}
	for (int i = 0; i < pos.size(); i++)
		if (pos[i] == t)
			return 1;
	return 0;
}

int main() {
	cin >> s >> xt >> yt;
	for (int i = 0; i < s.size();) {
		int cnt = 0, st = i;
		while (i < s.size() && s[i] == 'F')
			cnt++, i++;
		i++;
		if (st == 0)
			xt -= cnt;
		else if (fx)
			x.push_back(cnt);
		else
			y.push_back(cnt);
		fx = !fx;
	}
	if (check(x, xt) && check(y, yt))
		cout << "Yes";
	else
		cout << "No";
}