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
using namespace std;
typedef long long ll;

int main() {
	int x; cin >> x;
	int ans = 1;
	for (int i = 2; i <= x; i++) {
		int b = i;
		int a;
		for (int j = 2; pow(b,j) <= x; j++) {
			a = pow(b, j);
		}
		ans = max(a, ans);
	}
	cout << ans << endl;
}
