
// C - String Transformation

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

string normalize(string s) {
	char c = 'A';
	unordered_map<char, char> table;

	string result = "";
	for (int i=0; i<s.size(); i++) {
		if (! table[s[i]]) {
			table[s[i]] = c;
			result.push_back(c);
			c++;
		} else {
			result.push_back(table[s[i]]);
		}
	}

	return result;
}

int main() {
	string S, T;
	cin >> S >> T;

	S = normalize(S);
	T = normalize(T);

	//cout << S << endl; // **** debug ****
	//cout << T << endl; // **** debug ****

	string ans;
	if (S == T) ans = "Yes";
	else ans = "No";

	cout << ans << endl;

	return 0;
}