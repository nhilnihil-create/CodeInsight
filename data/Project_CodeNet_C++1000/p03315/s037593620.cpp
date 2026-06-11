#include"bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define int long long

signed main() {
	string s; cin >> s;
	int cnt = 0;
	rep(i, s.size()) {
		if (s[i] == '+')cnt++;
		else cnt--;
	}
	cout << cnt << endl;
}