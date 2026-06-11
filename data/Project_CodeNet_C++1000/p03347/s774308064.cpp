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
using namespace std;
typedef long long ll;

typedef pair<int, int> pii;
typedef tuple<int, int, int> ti3;

//const ll MOD_CONST = 1000000007;
const ll MOD_CONST = 998244353;


const int INF = 1000000000;
const ll BIG_NUM = 1000000000000000000;



int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	if (a[0] != 0) {
		cout << -1 << endl;
		return 0;
	}

	ll cnt = 0;
	
	for (int i = 0; i < n; i++) {
		if (a[i + 1] > a[i] + 1) {
			cout << -1 << endl;
			return 0;
		}

		if (a[i + 1] <= a[i]) {
			cnt += a[i];
		}


	}
	
	cout << cnt << endl;
}

