//IOI 2021
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define ff first
#define ss second

typedef long long ll;
typedef pair<int, int> pii;

string alph = "abcdefghijklmnopqrstuvwxyz";

string s;
set<char> st;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	for (char i = 'a'; i <= 'z'; i++)
		st.insert(i);
	reverse(alph.begin(), alph.end());
	cin >> s;
	if (s == alph)
		return cout << -1 << endl, 0;
	if (s.size() !=	26) {
		for (auto i : s)
			st.erase(i);
		s += *st.begin();
	}
	else {
		string t = s;
		s.pop_back();
		for (auto i : s)
			st.erase(i);
		while (t[s.size()] >= *st.rbegin()) {
			st.insert(s.back());
			s.pop_back();
		}
		s += *st.upper_bound(t[s.size()]);
	}
	cout << s << endl;
	return 0;
}
