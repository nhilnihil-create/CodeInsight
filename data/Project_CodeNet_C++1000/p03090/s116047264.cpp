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

	vector<vector<int> > vs;


	for (int i = 1; i <= n / 2; i++) {
		vector<int> v;
		v.push_back(i);
		v.push_back((n / 2) * 2 - i + 1);
		vs.push_back(v);
	}

	if (n % 2 == 1) {
		vector<int> v;

		v.push_back(n);
		vs.push_back(v);
	}
	/*
	rep(i, vs.size()) {
		rep(j ,vs[i].size()) {
			cout << vs[i][j] << " ";
		}
		cout << endl;
	}
	cout << "----" << endl;
	*/
	int size = vs.size();
	vector<pair<int, int > > ps;

	if (n == 3) {
		ps.push_back(mkp(1, 3));
		ps.push_back(mkp(2, 3));
	} else {
		for (int i = 0; i < size; i++) {
			for (int j = 0; j < vs[i].size(); j++) {
				if (n == 4 && i == 0) continue;
				int prev = (i - 1 + size) % size;

				for (int k = 0; k < vs[prev].size(); k++) {
					ps.push_back(mkp(vs[i][j],vs[prev][k]));
				}
			}	
		}
	}
	cout << ps.size() << endl;
	for (auto p : ps) {
		cout << p.first << " " << p.second << endl;
	}

	return 0;

}