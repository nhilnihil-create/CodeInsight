#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream> 
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>  
using namespace std;
#define Ma_PI 3.141592653589793
#define eps 0.00000000000000000000000001
#define LONG_INF 10000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007
#define MOD  998244353
#define REP(i,n) for(long long i = 0;i < n;++i)
long long inv(long long now) {
	long long ans = 1;
	long long te = MAX_MOD - 2LL;
	while (te != 0) {
		if (te % 2 == 1) {
			ans *= now;
			ans %= MAX_MOD;
		}
		te /= 2;
		now *= now;
		now %= MAX_MOD;
	}
	return ans;
}
long long summing[1000000] = {};
int main() {
#define int long long
	long long n, x;
	cin >> n >> x;
	vector<long long> geko;
	REP(i, n) {
		long long a;
		cin >> a;
		geko.push_back(a);
	}
	reverse(geko.begin(), geko.end());
	REP(i, geko.size()) {
		summing[i + 1] = summing[i] + geko[i];
	}
	for (int i = geko.size(); i < 1000000; ++i) {
		summing[i + 1] = summing[i];
	}
	long long final_ans = LONG_INF;
	for (long long k = 1; k <= n; ++k) {
		long long now_ans = x * (n + k);
		for (int q = 0; q < n; q += k) {
			long long going = q / k + 1;
			long long nya = summing[q + k] - summing[q];
			going = max(2 * going + 1, 5LL);
			if (LLONG_MAX - nya * going <= now_ans) {
				now_ans = -1;
				break;
			}
			now_ans += nya * going;
		}
		if (now_ans == -1) continue;
		final_ans = min(final_ans, now_ans);
	}
	cout << final_ans << endl;
	return 0;
}