#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i--)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 25;
const int MOD = 1e9+7;
 
int main() {
	string s,t;
	cin >> s >> t;
	int ls = s.size(), lt = t.size();
	if (ls < lt) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}

	vector<string> ans;
	for (int i = 0; i <= ls-lt; i++)
	{
		bool ok = true;
		for (int j = 0; j < lt; j++)
		{
			if (s[i+j] !='?' && s[i+j] != t[j]) ok = false;
		}
		if (ok) {
			string now = "";
			rep(k,i) {
				if (s[k]=='?') now+='a';
				else now += s[k];
			}
			now += t;
			for (int k = i+lt; k < ls; k++)
			{
				if (s[k]=='?') now+='a';
				else now+=s[k];
			}
			ans.push_back(now);
		}
	}
	if (ans.empty()) {
		cout << "UNRESTORABLE" << endl;
		return 0;
	}
	sort(ans.begin(), ans.end());
	cout << ans[0] << endl;
	
	return 0;
}