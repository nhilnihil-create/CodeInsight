#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int n;
	cin >> n;
	string s;
	if (n <= 999) s = "ABC";
	if (n > 999) s = "ABD";
	cout << s << endl;
	return 0;
}
