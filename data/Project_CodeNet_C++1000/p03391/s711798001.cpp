#include <cstdio>
#include <memory.h>
#include <cstring>
#include <vector>
#include <deque>
#include <cstdlib>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <functional>
#include <iostream>
#include <set>
#include <list>
#include <map>
#include <time.h>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#define sz(x) (int)(x).size()
#define all(x) (x).begin(), (x).end()
using namespace std;

typedef unsigned long long llu;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
const ll MOD = 1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

int a[200000], b[200000];

int main() {
	int n;
	scanf("%d", &n);

	// b가 엄격히 더 큰것의 개수.
	// 같은 건 또 어떻게 하지?
	//

	int cnt = 0, cc, miv = 1e9 + 7;
	ll sum = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a[i], &b[i]);
		sum += b[i];

		if (b[i] > a[i]) cnt++;
		else if (b[i] < a[i]) {
			cc = b[i];
			miv = min(miv, b[i]);
		}
	}

	if (cnt == 0) return !printf("0");
	else if (cnt == n - 1) return !printf("%lld", sum - cc);
	else return !printf("%lld", sum - miv);
}