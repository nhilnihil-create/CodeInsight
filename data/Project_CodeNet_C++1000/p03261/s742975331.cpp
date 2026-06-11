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
int main() {
	int n;
	bool f = 1;
	cin >> n;
	vector<string>s(n);
	for (int i = 0; i < n; i++) {
		cin >> s.at(i);
	}
	for (int i = 0; i < n-1; i++) {
		if (s.at(i)[s[i].size() - 1] != s.at(i + 1)[0])f = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i!=j&&s.at(i) == s.at(j))f = 0;
		}
	}
	if (f == 1)cout << "Yes" << endl;
	else cout << "No" << endl;
}