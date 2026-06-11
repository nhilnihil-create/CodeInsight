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
#include <numeric>

// https://umbccd.io/challenges


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> b(n);
	rep(i, n) {
		cin >> b[i];
	}
	vector<int> a;

	while(!b.empty()) {
		bool ok = false;
		for (int i = b.size() - 1; i >= 0; i--) {

			if (b[i] == i + 1) {
				b.erase(b.begin() + i);
				a.push_back(i + 1);
				ok = true;
				break;				
			}
		}
		if (ok == false) {
			cout << -1 << endl;
			return 0;
		}

	}
	rep(i, n) {
		cout << a[n - i - 1] << " " << endl;
	}



 	return 0;
}
