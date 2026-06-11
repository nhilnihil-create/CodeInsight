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

typedef long long ll;
typedef unsigned long long llu;
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<ll, ll> pll;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;
typedef pair<string, int> psi;
typedef pair<char, int> pci;
typedef pair<int, char> pic;
const ll MOD = (ll)1e9 + 7;
const long double PI = 3.141592653589793238462643383279502884197;

priority_queue<int, vector<int>, greater<int> > pq;
vector<int> v;

char a[200001];
char b[200001];

int main() {
	int h, w, n;
	scanf("%d %d %d", &h, &w, &n);

	int x, y;
	scanf("%d %d", &x, &y);

	scanf("%s %s", a, b);
	for (int i = 0; i < n; i++) {
		v.push_back(a[i]);
		v.push_back('#');
	}

	for (int i = 0; i < n; i++)
		v[i * 2 + 1] = b[i];

	int lh = 1, uh = h, lw = 1, uw = w;
	for (int i = 2 * n - 1; i >= 0; i--) {
		if (i % 2 == 1) {
			if (v[i] == 'U')
				uh = min(h, uh + 1);
			if (v[i] == 'D')
				lh = max(1, lh - 1);
			if (v[i] == 'L')
				uw = min(w, uw + 1);
			if (v[i] == 'R')
				lw = max(1, lw - 1);
		}
		else {
			if (v[i] == 'U')
				lh++;
			if (v[i] == 'D')
				uh--;
			if (v[i] == 'L')
				lw++;
			if (v[i] == 'R')
				uw--;
		}

		if (lh > uh || lw > uw) return !printf("NO");
	}
	
	if (!(lh <= x && x <= uh && lw <= y && y <= uw)) return !printf("NO");
	printf("YES");
}