#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int A, B, X;
	cin >> A >> B >> X;
	string ans = "NO";
	if (A <= X && X <= A + B) ans ="YES";
	cout << ans << endl;
	return 0;
}
