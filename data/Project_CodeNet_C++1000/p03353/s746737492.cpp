#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {        
	string s;
	cin >> s;
	int k;
	cin >> k;
	int n = (int)s.size();
	set<string> p;
	for (int i = 0; i  < n; ++i) {
		string o = "";
		for (int j = i; j < min(n, i + 5); ++j) {
			o += s[j];
			p.insert(o);
		}
	}
	auto it = p.begin();
	for (int i = 0; i < k - 1; ++i) {
		++it;
	}
	cout << *it;
}






