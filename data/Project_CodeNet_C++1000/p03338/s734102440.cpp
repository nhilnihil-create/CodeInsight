#include <bits/stdc++.h>

using namespace std;

string s;

int eval(int x) {
	set<char> a;
	for (int i = 0; i < x; i++){
		a.insert(s[i]);
	}
	int r = 0;
	set<char> b;
	for (int i = x; i < s.length(); i++){
		b.insert(s[i]);
	}
	for (auto y : b) {
		r+=a.count(y);
	}
	return r;
}

int main() {
	int n;
	cin >> n;
	cin >> s;
	int best = 0;
	for (int i = 1; i < s.length(); i++){
		best = max(best,eval(i));
	}
	cout << best << "\n";
}
