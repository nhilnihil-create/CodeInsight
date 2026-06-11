#include <iostream>
#include <iomanip>
#include <algorithm>
#include <utility>
#include <cmath>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <deque>


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

static ll b[200010];
static ll w[200010];


int main() {
	int n;
	string s;

	cin >> n >> s;

	for (int i = 0; i < n ; i++) {
		w[i + 1] = w[i];
		if (s[i] == '#') {
			w[i + 1]++;
		}
	}


	for (int i = n - 1; i >= 0; i--) {
		b[i] = b[i + 1];
		if (s[i] == '.') {
			b[i] ++;
		}
	}

	ll min = 1LL << 62;

	rep(i , n + 1) {
		//cout << "i:" << " b:" << b[i] << " w:" << w[i] << endl;
		ll cur = b[i] + w[i];
		if (cur < min) {
			min = cur;
		}
	}

	cout << min << endl;
	

	
	return 0;
}