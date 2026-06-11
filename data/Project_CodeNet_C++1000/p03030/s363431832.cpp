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
const int INF = 1000000001;
const long long LINF = 1e18;
const int MAX = 510000;

int main() {
	int n;
	string s;
	int p;
	cin >> n;
	map< pair<string, int>, int> a;
	vector<pair<string, int>> score(n);
	for (int i = 0; i < n; i++) {
		cin >> s >> p;
		score.at(i).first = s;
		score.at(i).second = -p;
		a[score.at(i)] = i;
	}
	sort(score.begin(), score.end());
	for (int i = 0; i < n; i++) {
		cout << a[score.at(i)] + 1 << endl;
	}
		return 0;
}