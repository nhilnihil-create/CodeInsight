#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 29;
 
int main() {
	string s, t;
	cin >> s >> t;
	int l = s.size();
	bool can = false;
	if (s == t) can = true;
	string hozon = s;
	rep(i, l)
	{
		string ss = hozon[l-1] + hozon.substr(0, l-1);
		hozon = ss;
		if (ss == t) can = true;
	}
	if (can) cout << "Yes" << endl;
	else cout << "No" << endl;
	
}