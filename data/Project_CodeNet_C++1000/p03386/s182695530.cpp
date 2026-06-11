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
	int a, b;
	cin >> a >> b;
	int k; cin >> k;
	int cnt = 1;
	for (int i = a; i <= b; i++) {
		if (cnt <= k || b - k + 1 <= i) {
			cout << i << endl;
		}
		cnt++;
	}
}
