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
	int cnt = 0;
	vector<int> a(3);
	cin >> a.at(0) >> a.at(1) >> a.at(2);
	sort(a.begin(), a.end());
	while (a.at(0) != a.at(1) || a.at(1) != a.at(2)) {
		if (a.at(1) != a.at(2)) {
			a.at(0)++;
			a.at(1)++;
			cnt++;
		}
		else if (a.at(1) == a.at(2) && a.at(0) != a.at(1)) {
			a.at(0) += 2;
			cnt++;
		}
		sort(a.begin(), a.end());

	}
	cout << cnt << endl;
		return 0;
	}
