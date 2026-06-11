#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int ans = abs(a-b)+abs(b-c)+abs(c-a) - max(max(abs(a-b),abs(b-c)),abs(c-a));
	cout << ans << endl;
	return 0;
}
