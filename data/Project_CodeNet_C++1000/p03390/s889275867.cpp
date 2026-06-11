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

int main() {
	int q;
	scanf("%d", &q);

	ll a, b;
	while (q--) {
		scanf("%lld %lld", &a, &b);

		if (a == b) {
			printf("%lld\n", (a - 1) * 2);
			continue;
		}
		else {
			ll sum = a * b;
			ll sq = sqrt(sum);

			if (sq * sq > sum) sq--;
			else if ((sq + 1) * (sq + 1) <= sum) sq++;

			if (sq * sq == sum) printf("%lld\n", (sq - 1) * 2 - 1);
			else if (sq * (sq + 1) >= sum) printf("%lld\n", (sq - 1) * 2);
			else printf("%lld\n", sq * 2 - 1);
		}
	}
}