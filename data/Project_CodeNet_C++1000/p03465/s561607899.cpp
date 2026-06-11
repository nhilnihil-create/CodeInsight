#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdio>
#include <iomanip>
#include <fstream>
#include <cassert>
#include <cstring>
#include <unordered_set>
#include <unordered_map>
#include <numeric>
#include <ctime>
#include <bitset>
#include <complex>
#include <chrono>
#include <random>
#include <functional>

using namespace std;

const int N = 2000;

bitset<N * N> can;

signed main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int n;
	cin >> n;
	int s = 0;
	can[0] = 1;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		s += x;
		can |= (can << x);
	}
	for (int i = 0; i < N * N; i++) {
		if (i >= s - i && can[i]) {
			cout << i << endl;
			return 0;
		}
	}
}