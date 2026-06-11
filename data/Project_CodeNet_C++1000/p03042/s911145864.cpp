#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < (int)n; ++i)
#define FOR(i, a, b) for(int i = a; i < (int)b; ++i)

using ll = long long;

const int Inf = 1e9;
const double EPS = 1e-9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int first = (s[0] - '0') * 10 + (s[1] - '0');
	int second = (s[2] - '0') * 10 + (s[3] - '0');
	if ((first >= 1 && first <= 12) && (second >= 1 && second <= 12)) {
	  cout << "AMBIGUOUS" << endl;
	} else if (first >= 1 && first <= 12) {
	  cout << "MMYY" << endl;
	} else if (second >= 1 && second <= 12) {
	  cout << "YYMM" << endl;
	} else {
	  cout << "NA" << endl;
	}
	
    return 0;
}
