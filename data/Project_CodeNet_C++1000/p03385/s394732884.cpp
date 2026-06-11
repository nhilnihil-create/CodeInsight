#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;

int main() {
	string s;
	cin >> s;
	sort(all(s));
	if(s == "abc") cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}