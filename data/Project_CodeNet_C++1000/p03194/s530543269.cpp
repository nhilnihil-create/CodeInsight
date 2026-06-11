#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
#include<math.h>
#include<queue>
#include<deque>
#include<stack>
#include<cstdio>
#include<utility>
#include<set>
#include<list>
#include<cmath>
#include<stdio.h>
#include<string.h>
#include<cstdio>
#include<iomanip>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using piii = pair<pii, pii>;
const int INF = 1e9 + 7;
int main() {
	ll N, P;
	cin >> N >> P;
	if (N == 1) {
		cout << P << endl;
		return 0;
	}
	ll ans = 1;
	ll a = 1;
	while (pow(a, N) <= P) {
		ll kake = pow(a, N);
		if (P%kake == 0)ans = a;
		a++;
	}
	cout << ans << endl;
	return 0;
}