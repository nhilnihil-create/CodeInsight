#define _USE_MATH_DEFINES

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <bitset>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef tuple<ll, ll, ll> tl3;



const int BIG_NUM = 1e9;
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;
//const ll MOD = 998244353;

const int MAX = 1e5+5;



int main() {
	int k;
	cin >> k;
	vector<int> a(k);
	for (int i = 0; i < k; i++) {
		cin >> a[i];
	}
	reverse(a.begin(), a.end());

	if (a[0] != 2) {
		cout << -1 << endl;
		return 0;
	}

	ll l = 2;
	ll r = 2;
	for(int i = 0;i<k;i++){
		ll x = (l / a[i]);
		if (l % a[i] != 0) {
			x++;
		}

		ll y = r / a[i];
		
		if (x > y) {
			cout << -1 << endl;
			return 0;
		}

		l = x * a[i];
		r = (y + 1) * a[i] - 1;

	}

	cout << l << " " << r << endl;


}