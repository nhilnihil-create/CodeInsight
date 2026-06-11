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
vector<int> xx, yy;

char s[8001];
int dpx[2][16001], dpy[2][16001];

int main() {
	scanf("%s", s);
	int n = strlen(s);

	int x, y;
	scanf("%d %d", &x, &y);

	int cnt = 0;
	int bit = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'F') cnt++;
		else {
			if (bit == 0) xx.push_back(cnt);
			else yy.push_back(cnt);
			cnt = 0;
			bit ^= 1;
		}
	}
	if (bit == 0) xx.push_back(cnt);
	else yy.push_back(cnt);

	x -= xx[0];
	xx.erase(xx.begin());

	x += 8000; y += 8000;
	dpx[1][8000] = 1;
	dpy[1][8000] = 1;
	
	for (int i = 0; i < sz(xx); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (j - xx[i] >= 0 && dpx[(i + 1) & 1][j - xx[i]])
				dpx[i & 1][j] = 1;
			if (j + xx[i] <= 16000 && dpx[(i + 1) & 1][j + xx[i]])
				dpx[i & 1][j] = 1;
		}
		memset(dpx[(i + 1) & 1], 0, sizeof(dpx[0]));
	}

	for (int i = 0; i < sz(yy); i++) {
		for (int j = 0; j <= 16000; j++) {
			if (j - yy[i] >= 0 && dpy[(i + 1) & 1][j - yy[i]])
				dpy[i & 1][j] = 1;
			if (j + yy[i] <= 16000 && dpy[(i + 1) & 1][j + yy[i]])
				dpy[i & 1][j] = 1;
		}
		memset(dpy[(i + 1) & 1], 0, sizeof(dpy[0]));
	}

	if (dpx[sz(xx) & 1 ^ 1][x] && dpy[sz(yy) & 1 ^ 1][y]) return !printf("Yes");
	else printf("No");
}