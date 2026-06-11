#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;

signed main() {
	string s;
	cin >> s;
	if(s == "abc" || s=="acb"||s=="bac"||s=="bca"||s=="cab"||s=="cba") cout << "Yes" << endl;
	else cout << "No" << endl;
}
