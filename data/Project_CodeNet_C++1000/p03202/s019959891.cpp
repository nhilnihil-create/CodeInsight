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

int N, A[200020];
map <int, int> Mx;
int chk;
void update(int x, int L) {
	Mx[x]++; if(x == 0) chk = 1;
	if(Mx[x] == L) { Mx[x] = 0, update(x - 1, L); }
}

int main() {
	scanf("%d", &N);
	for(int i=1;i<=N;i++) scanf("%d", A + i);
	int can1 = 1;
	for(int i=2;i<=N;i++) if(A[i] <= A[i-1]) can1 = 0;
	if(can1) {
		puts("1");
		return 0;
	}
	int low = 2, high = N, res = -1;
	while(low <= high) {
		int mid = (low + high) >> 1;
		Mx.clear(); chk = 0;
		for(int i=2;i<=N;i++) {
			if(A[i] <= A[i-1]) {
				update(A[i], mid);
				while(szz(Mx) && Mx.rbegin()->Fi > A[i]) Mx.erase(--Mx.end());
			}
		}
		if(chk) low = mid + 1;
		else high = mid - 1, res = mid;
	}
	printf("%d\n", res);
	return 0;
}
