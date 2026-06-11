#include<bits/stdc++.h>
const int MOD = 1e9+7;
#define REP(i,n) for (int i = 0; i < (n); ++i)
#define ar array
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);

	char C11,C12,C13,C21,C22,C23;
	cin >> C11 >> C12 >> C13 >> C21 >> C22 >> C23;

	if (C11==C23 && C12==C22 && C13==C21) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
