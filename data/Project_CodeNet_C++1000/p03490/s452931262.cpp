#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <memory.h>
#include <math.h>
#include <assert.h>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <iostream>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <bitset>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
#define Fi first
#define Se second
#define pb(x) push_back(x)
#define szz(x) ((int)(x).size())
#define rep(i, n) for(int i=0;i<n;i++)
#define all(x) (x).begin(), (x).end()
typedef tuple<int, int, int> t3;
typedef pair<ll, ll> pll;
typedef long double ldouble;
typedef pair<double, double> pdd;

char S[8080];
int x, y;

void solve() {
	scanf("%s", S);
	scanf("%d%d", &x, &y);
	int l = 0, L = (int)strlen(S);
	while(l < L && S[l] == 'F') ++l, --x;
	vector <int> v[2];
	for(int i=l, dir=0, c=0;i<=L;i++) {
		if(i == L || S[i] == 'T') {
			if(c > 0) v[dir].pb(c);
			c = 0;
			dir ^= 1;
		}
		else ++c;
	}
	int xx[2] = {x, y};
	rep(u, 2) {
		int vx = xx[u];
		const int ADD = 16020;
		bitset <ADD*2> B; B.reset();
		B[ADD] = 1;
		for(int e : v[u]) {
			B = (B >> e) | (B << e);
		}
		if(B[ADD + vx] == 0) {
			puts("No"); return;
		}
	}
	puts("Yes");
}

int main(){
	int Tc = 1; // scanf("%d\n", &Tc);
	for(int tc=1;tc<=Tc;tc++){
		solve();
	}
	return 0;
}


