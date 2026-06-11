#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

class IntervalTree { // find min, add to range
	using wgt = long long;

	static constexpr wgt no_val = (1LL<<60);

	struct node {
		wgt val, add;
		int l, r;
	};

	vector<node> T;

	void upd(int i) {
		node & n = T[i];
		n.val += n.add;
		if(n.l+1 < n.r) {
			T[2*i].add += n.add;
			T[2*i+1].add += n.add;
		}
		n.add = 0;
	}

public:
	IntervalTree() {}

	IntervalTree(int N) {
		int b = 1;
		while(b < N) b *= 2;
		T.reserve(2*b+1);
		T.resize(2, {no_val, 0, 0, b});
		for(int i = 1; ; i++) {
			if(i == (int)T.size() || T[i].l+1 == T[i].r) break;
			T.push_back({no_val, 0, T[i].l, (T[i].l+T[i].r)/2});
			T.push_back({no_val, 0, (T[i].l+T[i].r)/2, T[i].r});
		}
	}

	void add(int l, int r, wgt w_add, int i = 1) {
		node & n = T[i];
		if(n.l == l && n.r == r) {
			n.add += w_add;
			upd(i);
			return;
		}
		else if(n.add) upd(i);
		if(n.l >= r || l >= n.r) return;
		int c = (n.l + n.r) / 2;
		if(n.l+1 < n.r) {
			add(l, min(r, c), w_add, 2*i);
			add(max(l, c), r, w_add, 2*i+1);
			n.val = min(T[2*i].val, T[2*i+1].val);
		}
	}

	void put(int pos, wgt w, int i = 1) {
		node & n = T[i];
		if(n.l == pos && n.r == pos+1) {
			T[i].val = w;
			T[i].add = 0;
			return;
		}
		else if(n.add) upd(i);
		if(n.l > pos || pos >= n.r) return;
		put(pos, w, 2*i);
		put(pos, w, 2*i+1);
		n.val = min(T[2*i].val, T[2*i+1].val);
	}

	wgt get(int l, int r, int i = 1) { // max [l..r)
		node & n = T[i];
		if(n.add) upd(i);
		if(n.l >= r || l >= n.r) return no_val;
		if(n.l == l && n.r == r) return n.val;
		n.val = min(T[2*i].val, T[2*i+1].val);
		int c = (n.l + n.r) / 2;
		auto best_lft = get(l, min(r, c), 2*i);
		auto best_rt = get(max(l, c), r, 2*i+1);
		return min(best_lft, best_rt);
	}
};

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cat A, B;
	cin >> N >> A >> B;
	vector<int> P(N);
	for(int i = 0; i < N; i++) cin >> P[i];
	IntervalTree I(N+5);
	I.put(0, 0);
	for(int i = 0; i < N; i++) {
		cat cost = I.get(0, P[i]);
		I.put(P[i], cost);
		I.add(0, P[i], A);
		I.add(P[i]+1, N+3, B);
	}
	cout << I.get(0, N+3) << "\n";
	return 0;
}

// look at my code
// my code is amazing
