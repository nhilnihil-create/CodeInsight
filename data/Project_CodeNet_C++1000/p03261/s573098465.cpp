#include<iostream>
#include<cstdlib>
#include<utility>
#include<tuple>
#include<string>
#include<vector>
#include<numeric>
#include<algorithm>
#include<queue>
#include<deque>
#include<bitset>
#include<cmath>
#include<map>
#include<iomanip>
using namespace std;
using ll = long long int;
const ll mod = 1e9 + 7;
#define rep(i, a, b) for(int i = a; i < b; i++)

int main() {
	
	int n;
	cin >> n;

	vector<string> w(n);
	rep(i, 0, n) cin >> w[i];

	char last = w[0][0];
	map<string, int> m;
	rep(i, 0, n) {
		if (m[w[i]] == 0) m[w[i]] = 1;
		else {
			cout << "No" << endl;
			return 0;
		}
		int x = w[i].size();
		if (last != w[i][0]) {
			cout << "No" << endl;
			return 0;
		}
		last = w[i][x - 1];
	}
	cout << "Yes" << endl;

	return 0;
}