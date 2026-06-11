
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include<algorithm>
#include<sstream>
#include<iomanip>
#include<deque>
#include<list>


using namespace std;

typedef long long ll;

typedef pair<int, int> pii;

const ll MOD_CONST = 1000000007;
const ll BIG_NUM = 1000000000000000000;
const int BIG_INT = 1000000000;


int gcd(int a, int b) {
	if (a == 0) {
		return b;
	}
	if (a > b) {
		swap(a, b);
	}
	
	return gcd(b%a, a);
}

int main() {
	int n, m;
	cin >> n >> m;
	ll lcm = 1LL * n * m / gcd(n, m);

	
	string s, t;
	cin >> s >> t;
	
	bool canConsist = true;
	
	for (ll i = 0; i < n;i += lcm/m) {
		if (s[i] != t[i*  (lcm / n)/(lcm/m)]) {
			canConsist = false;
		}
	}

	cout << (canConsist ? lcm : -1) << endl;
}

