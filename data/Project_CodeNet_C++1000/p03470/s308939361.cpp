#include <iostream>
#include <cmath>
#include <algorithm>
#include <bitset>
#include <iomanip>
#include <cstdio>
#include <new>
#include <vector>
#include <cstdlib>
#include <string>
#include <set>
#include <tuple>　
#include<map>
#include<queue>

using namespace std;


int main() {
	int N;
	cin >> N;
	vector<int> d(N);

	for (int i = 0; i < N; ++i) {
		cin >> d.at(i);
	}

	sort(d.begin(), d.end());
	reverse(d.begin(), d.end());

	int ans = 1;

	for (int i = 1; i < N; ++i) {
		if (d.at(i) < d.at(i - 1)) ans += 1;
	}

	cout << ans << endl;
}