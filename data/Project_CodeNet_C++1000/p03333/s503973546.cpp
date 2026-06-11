#include <bits/stdc++.h> 
using namespace std;
 
#define sz(x) (int)x.size() 
#define pb push_back 
#define mp make_pair 
#define fi(a, b) for(int i=a; i<=b; i++) 
#define fj(a, b) for(int j=a; j<=b; j++) 
#define fo(a, b) for(int o=a; o<=b; o++) 
#define fdi(a, b) for(int i=a; i>=b; i--) 
#define fdj(a, b) for(int j=a; j>=b; j--) 
#define fdo(a, b) for(int o=a; o>=b; o--) 
 
#ifdef LOCAL
#define err(...) fprintf(stderr, __VA_ARGS__)
#else
#define err(...) while(false) {}
#endif
 
typedef long long ll; 
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll; 
typedef vector<int> vi; 
typedef vector<ll> vll;
typedef vector<pii> vpii; 
typedef vector<pll> vpll; 
typedef long double ld;
typedef unsigned long long ull;
 
/////////////////////////////////
 
int const MAX = 1e5 + 41;
int const INF = 1e9 + 41;
 
pii const EMP = mp(INF, INF);
 
int n;
int l[MAX];
int r[MAX];
ll ans;
ll ans1, ans2;
multiset<pii> lr, rl;
 
pii getleft() {
	if (sz(rl) == 0) return EMP;
	return (*rl.begin());
}
 
pii getright() {
	if (sz(lr) == 0) return EMP;
	return (*lr.rbegin());
}
 
void rem(int l, int r) {
	lr.erase(lr.find(mp(l, r)));
	rl.erase(rl.find(mp(r, l)));	
}
 
bool inside(int l, int r, int x) {
	return (l <= x && x <= r);
}
 
int getlrdist(pii p, int x) {
	int l = p.first;
	int r = p.second;
	if (inside(l, r, x)) return -INF;
	if (x > r) return -INF;
	return l - x;
}
 
int getrldist(pii p, int x) {
	int l = p.second;
	int r = p.first;
	if (inside(l, r, x)) return -INF;
	if (x < r) return -INF;
	return x - r;
}
 
void solve1() {
	lr.clear();
	rl.clear();
	fi(1, n) {
		lr.insert(mp(l[i], r[i]));
	}
	fi(1, n) {
		rl.insert(mp(r[i], l[i]));
	}
	int x = 0;
	bool f = 1;
	while (1) {
		pii l = getleft();//rl
		pii r = getright();//lr
//		err("x = %d l = %d %d r = %d %d dl = %d dr = %d\n", x, l.second, l.first, r.first, r.second, getrldist(l, x), getlrdist(r, x));
		if (l == r && l == EMP) break;
		if (l == EMP) {
			if (getlrdist(r, x) == -INF) break;
			ans1 += getlrdist(r, x);
			x = r.first;
			rem(r.first, r.second);
		} else if (r == EMP) {
			if (getrldist(l, x) == -INF) break;
			ans1 += getrldist(l, x);
			x = l.first;
			rem(l.second, l.first);								
		} else {
			if (getlrdist(r, x) == -INF && getrldist(l, x) == -INF) break;						
			if (!f && getlrdist(r, x) > getrldist(l, x)) {
				ans1 += getlrdist(r, x);
				x = r.first;
				rem(r.first, r.second);			
			} else {
				ans1 += getrldist(l, x);
				x = l.first;
				rem(l.second, l.first);												
			}
		}
		f = 0;
	}
 
	ans1 += abs(x);
	ans = max(ans, ans1);
}
 
void solve2() {
	lr.clear();
	rl.clear();
	fi(1, n) {
		lr.insert(mp(l[i], r[i]));
	}
	fi(1, n) {
		rl.insert(mp(r[i], l[i]));
	}
	int x = 0;
	bool f = 1;
	while (1) {
		pii l = getleft();//rl
		pii r = getright();//lr
//		err("x = %d l = %d %d r = %d %d dl = %d dr = %d\n", x, l.second, l.first, r.first, r.second, getrldist(l, x), getlrdist(r, x));
		if (l == r && l == EMP) break;
		if (l == EMP) {
			if (getlrdist(r, x) == -INF) break;
			ans2 += getlrdist(r, x);
			x = r.first;
			rem(r.first, r.second);
		} else if (r == EMP) {
			if (getrldist(l, x) == -INF) break;
			ans2 += getrldist(l, x);
			x = l.first;
			rem(l.second, l.first);								
		} else {
			if (getlrdist(r, x) == -INF && getrldist(l, x) == -INF) break;						
			if (f || getlrdist(r, x) > getrldist(l, x)) {
				ans2 += getlrdist(r, x);
				x = r.first;
				rem(r.first, r.second);			
			} else {
				ans2 += getrldist(l, x);
				x = l.first;
				rem(l.second, l.first);												
			}
		}
		f = 0;
	}
 
	ans2 += abs(x);
	ans = max(ans, ans2);
}
 
void solve() {
	solve1();
	solve2();
	printf("%lld\n", ans);
}
 
 
int main() {
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
 
	scanf("%d", &n);
	fi(1, n) {
		scanf("%d %d", &l[i], &r[i]);
	}  
	solve();		
 
	
#ifdef LOCAL
	err("ELAPSED TIME: %.3Lf\n", (ld) clock() / CLOCKS_PER_SEC);
#endif	
	
	return 0;
}