#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
using namespace std;
using ll = long long;
const int maxn = 303, mod = 1e9 + 7;
string s;
int n, q;

ll d, m, dm, ans;
void add(int i) {
	if(s[i] == 'C') ans += dm;
	if(s[i] == 'M') m++, dm += d;
	if(s[i] == 'D') d++;
}
void pop(int i) {
	if(s[i] == 'M') m--;
	if(s[i] == 'D') d--,  dm -= m;
}

ll solve(int k) {
	d = 0, m = 0, dm = 0, ans = 0;
	for(int i = 0; i < n; i++) {
		if(i - k >= 0) pop(i-k);
		add(i);
	}
	return ans;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s >> q;
	for(int k; q--;) {
		cin >> k;
		cout << solve(k) << '\n';
	}
	return 0;
}
