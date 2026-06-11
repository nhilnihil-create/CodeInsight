#include<iostream>
#include<string>
#include<vector>
#include<numeric>
#include<math.h>
#include<algorithm>
#include<iomanip>
#include<bitset>
using namespace std;

int main() {

	int N, T;
	cin >> N >> T;

	vector<int> cst;
	cst.clear();
	int cv, tv;
	for (int i = 0; i < N; i++) {
		cin >> cv >> tv;
		if (tv <= T) {
			cst.push_back(cv);
		}
	}

	if (cst.size() == 0) {
		cout << "TLE" << endl;
	}
	else {
		cout << *min_element(cst.begin(), cst.end()) << endl;
	}

	return 0;
}

