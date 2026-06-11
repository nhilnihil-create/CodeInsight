#include <bits/stdc++.h>

using namespace std;
using llong = long long;
using P = pair<llong, llong>;

#define BE(x) x.begin(), x.end()

const llong inf = llong(1e18)+7;
const llong mod = 1e9+7;

int main(){
	string s;

	cin >> s;
	for(int i = 0; i < 8; i++)
		s.pop_back();

	cout << s << endl;

	return 0;
}