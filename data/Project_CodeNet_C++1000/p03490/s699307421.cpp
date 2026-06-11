#include <bits/stdc++.h>
using namespace std;


vector<int> d;

set<int> px, tx, py, ty;

int main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	string s;
	int x,y;
	cin >> s >> x >> y;
	s += 'T';
	for(int i = 0, r = 0; i < s.size(); ++i) {
		if(s[i] == 'F') ++r;
		else d.push_back(r), r = 0;
	}
	px.insert(d[0]);
	py.insert(0);
	for(int i = 1; i < d.size(); ++i) {
		if(i&1) {
			ty.clear();
			for(int y : py) {
				ty.insert(y-d[i]);
				ty.insert(y+d[i]);
			}
			swap(ty,py);
		} else {
			tx.clear();
			for(int x : px) {
				tx.insert(x-d[i]);
				tx.insert(x+d[i]);
			}
			swap(tx,px);
		}
	}
	if(px.count(x) && py.count(y)) {
		cout << "Yes\n";
	} else cout << "No\n";
}