#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include<iomanip>

using namespace std;
typedef long long ll;

int main() {
	int N;
	cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; i++) cin >> a[i];

	map<int, int> x;
	for (int i = 0; i < N; i++) x[a[i]]++;
	int ans = 0;
	for (auto p: x) {
		int x1 = p.first;
		int x2 = p.second;
		if (x2 < x1) ans += x2;
		else ans += x2 - x1;
	}
	cout << ans << endl;
}
