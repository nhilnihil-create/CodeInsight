#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1000000007;

int main(int, char**) {
	string s1, s2;
	cin >> s1 >> s2;
	reverse(s1.begin(), s1.end());
	if (s1==s2) cout << "YES" << endl;
	else cout << "NO" << endl;
	return 0;
}