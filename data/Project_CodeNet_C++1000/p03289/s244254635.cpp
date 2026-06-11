#include <iostream>
#include <vector>
#include<algorithm>
#include<string>
#include<stdio.h>
#include<map>
#include<math.h>
#include<queue>
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
const int mod = 1000000007;
const int INF = 1000000000;
const long long LINF = 1e18;
const int MAX = 510000;

int main(){
	string s;
	int ci;
	bool f = 0;
	cin >> s;
	if (s[0] != 'A') {
		cout << "WA" << endl;
		return 0;
	}
	for (int i = 2; i < s.size()-1; i++) {
		if (s[i] == 'C') {
			ci = i;
			f = 1;
			break;
		}
	}
	if (f == 0) {
		cout << "WA" << endl;
		return 0;
	}
	for (int i = 1; i < s.size(); i++) {
		if (i != ci && 'z' - s[i] > 31)f = 0;
	}
	if (f == 0)cout << "WA" << endl;
	else {
		cout << "AC" << endl;
	}
	//cout <<'z'-'Z'  << endl;;

	return 0;
}