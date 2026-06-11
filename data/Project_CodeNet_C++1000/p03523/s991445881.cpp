#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define trav(a, x) for (auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	string s; cin >> s;
	bool m = regex_match(s, regex("^A?KIHA?BA?RA?$"));
	cout << (m ? "YES" : "NO") << endl;
}
