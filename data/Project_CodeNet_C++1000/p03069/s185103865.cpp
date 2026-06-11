#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const ll MOD = 1000000007;
const ll INF = 1LL<<60;
//int INF = numeric_limits<int>::max();

int main(int, char**) {
	int n; cin >> n;
	string s; cin >> s;
	vector<int> W(n), B(n);
	int cntw = 0;
	int cntb = 0;
	for (int i=0; i<n; i++) {
		if (s[i]=='#') cntb++;
		B[i] = cntb;
		if (s[n-1 - i]=='.') cntw++;
		W[n-1-i] = cntw;
	}
	int ret = W[0];
	W.push_back(0);
	for (int i=0; i<n; i++) {
		ret = min(ret, B[i] + W[i+1]);
	}
	cout << ret << endl;
	return 0;
}