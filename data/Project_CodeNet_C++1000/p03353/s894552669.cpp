#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

	string s; cin >> s;
	int n = s.size();
	int k; cin >> k;

	set<string> sub;
	REP(i, n) for (int j = 1; j <= k; j++) {
		sub.insert(s.substr(i, j));
	}

	int i = 0;
	for (auto x : sub) {
		i++;
		if (i == k) {
			cout << x << '\n';
			return 0;
		}
	}
    return 0;
}
