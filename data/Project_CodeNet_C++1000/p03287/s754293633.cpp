#include <memory.h>

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

#define mod 1000000007

int main() {
	int n, m;
	cin >> n >> m;
	long long int suma[100000];
	for (int i = 1; i <= n; i++) {
		long long int a;
		cin >> a;
		suma[i] = (suma[i - 1] + a) % m;
	}
	long long int ans = 0;
	map<long long int, long long int> cnt;
	cnt[0] = 1;
	for (int i = 1; i <= n; i++) {
		if (cnt.find(suma[i]) != cnt.end()) {
			ans += cnt[suma[i]];
			cnt[suma[i]]++;
		} else {
			cnt[suma[i]] = 1;
		}
	}
	cout << ans << endl;
}