#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <stdlib.h>
#include <string.h>
#include <cmath>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <set>
const long long MOD = 1000000007;
using namespace std;
typedef long long ll;

map<ll, int> mp;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s;
	int w;
	cin >> s;
	cin >> w;
	vector<string> a((s.size() + w - 1) / w);
	int tmp = 0;
	int counter = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i - counter == w) {
			tmp++;
			counter += w;
		}
		a[tmp] += s[i];
	}
	for (int i = 0; i < (s.size() + w - 1) / w; i++) {
		cout << a[i].at(0);
	}
	cout << endl;
 	return 0;
}