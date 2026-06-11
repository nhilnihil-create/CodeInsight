#include <bits/stdc++.h>
using namespace std;

const int ADD = 1e4, N = ADD << 1;

int x, y, cnt;
string s;
vector<int> X, Y;
bitset<N> b;

bool can(vector<int> vec, int want, bool B = false) {
	b.reset();
	b[ADD] = true;
	for (int i = 0; i < vec.size(); i++) {
		if(i == 0) {
			if(B)
				b <<= vec[i];
			else
				b = (b << vec[i]) | (b >> vec[i]);
		}
		else
			b = (b << vec[i]) | (b >> vec[i]);
	}
	return b[ADD + want];
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> s >> x >> y;
	s.push_back('T');
	for (char c: s)
		if(c == 'F')
			cnt++;
		else {
			if(X.size() <= Y.size())
				X.push_back(cnt);
			else
				Y.push_back(cnt);
			cnt = 0;
		}
	
	cout << (can(X, x, true) && can(Y, y)? "Yes": "No");
	return 0;
}