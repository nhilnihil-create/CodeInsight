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

// 10000 1 2
//  

using namespace std;

using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)



int main() {
	ll N;
	cin >> N;
	
	for(int h = 1; h <= 3500; h++) {
		for(int n = 1; n <= 3500;n ++) {
			ll left = 4 * h * n - N * (n + h);
			ll right = N * h * n;

			if (left > 0 && right % left == 0) {
				cout << h << " " << n <<  " " << right / left << endl;
				return 0;
			}
		}
	}
	return 0;
}