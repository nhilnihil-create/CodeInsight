#include <sys/time.h>

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
#include <utility>
#include <cctype>

using namespace std;

using ll = long long;
using P = pair<double, double>;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)
ll mod = 1000000007LL;

int calc(int a, vector<int>& ls) {
	int ans = (ls.size() - 1 ) * 10;
	int total = 0;
	for(int l : ls) {
		total += l;
	}
	return (ls.size() - 1 ) * 10 + abs(total - a);

}

int main() {
	int n,a,b,c;
	cin >> n >> a >> b >> c;
	vector<int> l(n);

	rep(i, n) {
		cin >> l[i];
	}
	
	int size = 1 << (n * 2);
	int min_v = 1e9;
	rep(i, size) {
		vector<int> ia;
		vector<int> ib;
		vector<int> ic;

		int bit = i;
		int cur = 0;

		while(bit > 0) {
			int b = bit & 3;

			if (b == 3) {
				ia.push_back(l[cur]);
			} else if (b == 2) {
				ib.push_back(l[cur]);
			} else if (b == 1) {
				ic.push_back(l[cur]);
			}
			cur++;
			bit /= 4;
		}

		if (ia.size() == 0 || ib.size() == 0 || ic.size() == 0) {
			continue;
		}
		/*
		cout << "****" << endl;
		for(int ta: ia) {
			cout << ta << " ";
		}
		cout << endl;
		for(int tb: ib) {
			cout << tb << " ";
		}
		cout << endl;

		for(int tc: ic) {
			cout << tc << " ";
		}
		cout << endl;
		*/

		min_v = min(min_v, calc(a, ia) + calc(b, ib) + calc(c, ic));
	}
	cout << min_v << endl;

	return 0;
}
