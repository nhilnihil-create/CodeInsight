#include <iostream>
#include <cmath>
#include <climits>
#include <string>
#include <numeric>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <functional>
#include <iomanip>
#include <set>

using namespace std;
using ll = long long;

template<typename T> void print(T t) { cout << t << endl; }

int main() {
	int N, M, D, T;
	cin >> N;
	multiset<int> dset;
	for (int i = 0; i < N; i++) {
		cin >> D;
		dset.insert(D);
	}
	
	cin >> M;
	for (int i = 0; i < M; i++) {
		cin >> T;
		auto itr = dset.find(T);
		if (itr == dset.end()) {
			print("NO");
			return 0;
		}
		else {
			dset.erase(itr);
		}
	}
	print("YES");
	return 0;
}