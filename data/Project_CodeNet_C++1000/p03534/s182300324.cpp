#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using ldbl = long double;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	string s;
	vector<int> alp(3,0);

	cin >> s;
	for(auto x: s)
		alp[x-'a']++;
	sort(BE(alp));
	int mini = alp[0];
	alp[0] -= mini;
	alp[1] -= mini;
	alp[2] -= mini;

	if(alp[2] >= 2)
		cout << "NO" << endl;
	else
		cout << "YES" << endl;

	return 0;
}