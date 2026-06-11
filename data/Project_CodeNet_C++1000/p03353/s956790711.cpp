#include <bits/stdc++.h>

using namespace std;

#define intt long long
#define FAST ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int N = 1005;

int n;
int a[N];

int main() {

	FAST;

	string s;
	int k;
	cin >> s >> k;
	set <string> subs;
	for (int i = 0; i < s.length(); i ++) {
		string tmp = "";
		for (int j = i; j < min(int(s.length()), i + 5); j ++) {
			tmp += s[j];
			subs.insert(tmp);
		}
	}
	k --;
	while (k) {
		subs.erase(subs.begin());
		k --;
	}
	cout << *subs.begin() << '\n';
	return 0;
}