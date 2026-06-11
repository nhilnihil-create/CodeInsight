#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	int n, k; cin >> n >> k;
	string s; cin >> s;
	char tmp = s[k - 1];
	s[k - 1] = (tmp - 'A') + 'a';
	cout << s << endl;
	return 0;
}