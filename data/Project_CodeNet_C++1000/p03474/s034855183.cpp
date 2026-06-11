#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <utility>
typedef long long ll;
const int INF = 1e9+1;
const int MOD = 1e9 + 7;
const ll LINF = 1e18;
using namespace std;

int main() {

	int a, b;
	bool f = 1;
	string s;
	cin >>a>>b>> s;

	for (int i = 0; i < s.size(); i++) {
		if (i != a && s[i] == '-')f = 0;
		if (s[a] != '-')f = 0;
	}

	if (f == 1)cout << "Yes" << endl;
	else cout << "No" << endl;

	return 0;
}