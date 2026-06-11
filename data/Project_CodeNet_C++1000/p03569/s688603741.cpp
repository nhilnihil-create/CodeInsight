#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string s;
	cin >> s;
	int l = 0, r = s.size()-1;
	int ans = 0;
	while (l < r)
	{
		if (s[l] == s[r]) {l++; r--;}
		else if (s[l] == 'x') {l++; ans++;}
		else if (s[r] == 'x') {r--; ans++;}
		else {
			cout << -1 << endl;
			return 0;
		}
	}
	cout << ans << endl;
	return 0;
}