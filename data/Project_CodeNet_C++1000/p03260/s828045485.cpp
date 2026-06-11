#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
	int A, B;
	cin >> A >> B;
	string ans = "No";
	for (int i = 1; i<=3; i++){
		if (A*B*i%2 == 1) ans = "Yes";
	}
	cout << ans << endl;
	return 0;
}
