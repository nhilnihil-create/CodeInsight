#include <iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<queue>
#include<cmath>
#include<set>
#include<deque>
#include<iomanip>
#include<tuple>
#include<stack>

#define _USE_MATH_DEFINES
#include<math.h>


using namespace std;
typedef long long ll;

typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;
typedef tuple<int, int, int> ti3;

const ll MOD_CONST = 1000000007;
//const ll MOD_CONST = 998244353;


const int BIG_NUM = 1000000005;
const ll INF = 1000000000000000000;

//const vector<vector<int>> DIR{ {1,0},{0,1},{-1,0},{0,-1} };

//const double EPS = 1e-10;


int main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	vector<ll> sum;
	for (int i = 0; i < n; i++) {
		ll s = a[i];
		sum.emplace_back(s);
		for (int j = i + 1; j < n; j++) {
			s += a[j];
			sum.emplace_back(s);
		}
	}

	sort(sum.begin(), sum.end());

	vector<ll> v;
	for (int i = 63; i >= 0; i--) {
		if (v.size() == k) {
			break;
		}
		if (v.size() <=0) {
			for (int j = 0; j < sum.size(); j++) {
				if ((sum[j] >> i) & 1) {
					v.emplace_back(sum[j]);
				}
			}

			/*
			for (int vi : v) {
				cout << vi << " ";
			}
			cout << endl;
			*/
			if (v.size() < k) {
				v = vector<ll>();
			}
			continue;
		}

		vector<ll> newV;
		for (auto it = v.begin(); it != v.end(); it++) {
			if ((*it >> i) & 1) {
				newV.emplace_back(*it);
			}
		}
		if (newV.size() >= k) {
			v = newV;
		}
		
	}

	ll ans = 0;
	if (v.size() >= k) {
		ans = v[0];
		for (int i = 0; i < k; i++) {
			ans = (ans & v[i]);
		}
	}
	cout << ans << endl;


}

