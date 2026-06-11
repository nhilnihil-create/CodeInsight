#include <bits/stdc++.h>
const int MOD = 1e9+7;
#define REP(i,n) for (int i = 0; i < (N); ++i)
#define ar array
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main () {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	int a,b;
	cin >> a >> b;

	if ((a*b)%2==0) {
		cout << "Even" << endl;
	}	else {
		cout << "Odd" << endl;
	}
	return 0;
}
