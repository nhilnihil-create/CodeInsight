#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
ll string_to_int(string x) {
	if (x == "") {
		return 0;
	}
	ll pn;
	stringstream s(x);
	s >> pn;
	return pn;
}
set<string> s;

void rec(string st) {
	if (string_to_int(st) > n) return ;
	s.insert(st);
	rec(st + "3");
	rec(st + "5");
	rec(st + "7");
}


int main() {
    cin >> n;
    rec("");
    int cnt = 0;
   // for (int i = 0; i < (int)s.size(); ++i) {
		//cout << s[i] << "\n";
    map<string,int> m;
	for (auto &x : s) {
		//cout << x << "\n";
		int five = 0, three = 0, seven = 0;
		for (int j = 0; j < (int)x.size(); ++j) {
			if (x[j] == '5') five++;
			if (x[j] == '3') three++;
			if (x[j] == '7') seven++;
			if (five && seven  && three && !m[x]) {
				//cout << x << "\n";
				cnt++;
				m[x] = 1;
			}
		}
	}
    cout << cnt;
}

