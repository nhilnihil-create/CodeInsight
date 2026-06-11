#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	string S;
	cin >> S;
	string ans = "No";
	if (S == "abc" || S == "acb" || S == "bca" || S == "bac" || S == "cab" || S == "cba") ans ="Yes";
	cout << ans << endl;
	return 0;
}
