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


using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define mkp(a, b) make_pair(a, b)


using namespace std;



int main() {
	int n;
	cin >> n;
	int count = 0;

	vector<int> ps;
	int cur = 2;
	while(count < n) {
		bool is_prime = true;
		for (int p : ps) {
			if (cur % p == 0) {
				is_prime = false;
				break;
			}
		}
		if (is_prime) {
			ps.push_back(cur);
			if (cur % 5 == 1) {
				cout << cur << endl;
				count ++;
			}
		}
		cur ++;
	}
	return 0;

}