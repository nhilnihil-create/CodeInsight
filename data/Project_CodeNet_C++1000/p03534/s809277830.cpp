#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <utility>
#include <functional>
#include <deque>
#include <cctype>
#include <stack>
#include <bitset>
#include <set>

using namespace std;
using ll = long long;
typedef unsigned long long ull;
typedef pair<ll, ll> P;

const ll MOD = 1000000007;
const ll INF = 1 << 30;
const ll INF2 = 9000000000000000000LL;
const double INF3 = 900000000000000;
const int dx[4] = { 1,0,-1,0 }, dy[4] = { 0,1,0,-1 };
const int tx[8] = { -1,0,1,-1,1,-1,0,1 }, ty[8] = { -1,-1,-1,0,0,1,1,1 };
#define ALL(x) (x).begin(),(x).end()
#define pb push_back
#define fi first
#define sc second


int main() {
	string s;
	int a = 0, b = 0, c = 0;
	cin >> s;
	for (int i = 0;i < s.size();i++) {
		if (s[i] == 'a')a++;
		else if (s[i] == 'b')b++;
		else c++;
	}
	if (a == b) {
		if (c == a - 1 || c == a || c == a + 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (a == c) {
		if (b == a - 1 || b == a + 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (c == b) {
		if (a == c - 1 || a == c + 1)cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else cout << "NO" << endl;
}