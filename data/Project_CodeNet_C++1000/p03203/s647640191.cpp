#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_set>
#include <bitset>
#include <time.h>
#include <limits.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) (int)x.size()
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) x.begin(),x.end()
typedef tuple<int, int, int> t3;

int H, W, N;

int main() {
	scanf("%d%d%d", &H, &W, &N);
	set <pii> Sx;
	for(int i=1;i<=N;i++) {
		int x, y; scanf("%d%d", &x, &y);
		Sx.insert(pii(x, y));
	}
	for(int i=1;i<=H+1;i++) Sx.insert(pii(i, W + 1));
	for(int i=1;i<=W;i++) Sx.insert(pii(H + 1, i));
	int c = 1;
	for(int i=1;i<=H+1;i++) {
		auto it = Sx.upper_bound(pii(i, -1));
		if(it->Fi == i && it->Se < c) {
			printf("%d\n", i - 1);
			return 0;
		}
		if(it->Fi == i && it->Se == c);
		else ++c;
	}
	return 0;
}
