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
	int A, B;
	cin >> A >> B;
	int K; cin >> K;
	int cnt = 0;
	int ans = 0;
	int div = min(A, B);
	for (int i = div; cnt < K; i--) {
		if (A % i == 0 && B % i == 0) {
			cnt++;
			ans = i;
		}
	}
	cout << ans << endl;
}
