#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <map>
#include <deque>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <bitset>
#include <sstream>
#include <new>
#include <typeinfo>
#include <iterator>

typedef long long ll;
typedef unsigned long long ull;
constexpr ll mop = 1000000007;
constexpr ll mop2 = 998244353;

using namespace std;



int main() {
	ll n;
	string s;
	cin >> n >> s;
	vector<ll> list;
	list.resize(n + 1);
	list[0] = 0;
	ll tmpB = 0;
	for (ll i = 1; i <= n; i++) {
		if (s[i - 1] == '#') {
			tmpB++;
		}
		list[i] = tmpB;
	}
	ll ans = INT64_MAX;
	ll numBlack = list[n];
	for (ll i = 0; i <= n; i++) {
		ll tmp = list[i] + ((n - numBlack) - (i - list[i]));
		if (ans > tmp) {
			ans = tmp;
		}
	}
	cout << ans << endl;

}
