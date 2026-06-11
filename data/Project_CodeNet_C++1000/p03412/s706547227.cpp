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

int a[200000];
int b[200000];
int pp[31][200000];

int main() {
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);

	for (int i = 1; i < 30; i++) {
		for (int j = 0; j < n; j++)
			pp[i][j] = b[j] % (2 << i);
		sort(pp[i], pp[i] + n);
	}

	int cc = 0;
	for (int i = 0; i < n; i++)
		cc += b[i] % 2;

	int ans = 0;
	int cnt;

	for (int i = 0; i < n; i++) {
		int ttt = a[i] % 2;

		if (ttt == 1) cnt = n - cc;
		else cnt = cc;
		if (cnt % 2) ans ^= 1;

		for (int j = 1; j < 30; j++) { // 2^j자리를 결정하다
			int tt = a[i] % (2 << j);
			cnt = n - (lower_bound(pp[j], pp[j] + n, (1LL << j) - tt) - pp[j]); // tt + 임의의 값이 1 << j를 넘는 것의 개수.
			cnt -= n - (lower_bound(pp[j], pp[j] + n, (2LL << j) - tt) - pp[j]); // tt + 임의의 값이 2 << j를 넘는 것의 개수.
			cnt += n - (lower_bound(pp[j], pp[j] + n, (3LL << j) - tt) - pp[j]);

			if (cnt % 2) ans ^= (1 << j);
		}
	}



	printf("%d", ans);
}