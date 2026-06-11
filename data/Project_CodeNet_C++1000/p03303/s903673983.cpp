#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	string s;
	llong w;

	cin >> s >> w;
	for(int i = 0; i < (int)s.size(); i += w)
		cout << s[i];
	cout << endl;

	return 0;
}