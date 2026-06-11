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
	string s,ans;
	bool f = 0;
	long long int cnt = 0,m,k;
	cin >> s >> k;
	m = s.size();
	for (int i = 0; i <min(m, k); i++) {
		if (s[i] != '1') {
			ans = s[i];
			f = 1;
			break;
		}
	}
	if (f == 0)cout << 1 << endl;
	else {
		cout << ans << endl;
	}
		return 0;
	}
