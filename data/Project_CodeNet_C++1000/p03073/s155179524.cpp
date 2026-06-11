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
	string s;
	int cnt = 0;
	cin >> s;
	for (int i = 0; i < s.size()-1; i++) {
		if (s[i] == s[i + 1] && s[i] == '0') {
			s[i + 1] = '1';
			cnt++;
		}
		else if (s[i] == s[i + 1] && s[i] == '1') {
			s[i + 1] = '0';
			cnt++;
		}

	}
	cout << cnt << endl;
	return 0;

}