#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 100010;
int _w;

struct Triple {
	int i, l, r;
	Triple() {}
	Triple( int i, int l, int r ):
		i(i), l(l), r(r) {}
};

struct Cmp1 {
	bool operator()( Triple a, Triple b ) const {
		if( a.r == b.r ) return a.i < b.i;
		else return a.r < b.r;
	}
};

struct Cmp2 {
	bool operator()( Triple a, Triple b ) const {
		if( a.l == b.l ) return a.i < b.i;
		else return a.l > b.l;
	}
};

int n, L[N], R[N];
set<Triple,Cmp1> s1;
set<Triple,Cmp2> s2;

void init() {
	s1.clear();
	s2.clear();
	for( int i = 1; i <= n; ++i ) {
		Triple tmp(i, L[i], R[i]);
		s1.insert(tmp);
		s2.insert(tmp);
	}
}

ll move( ll &p, Triple t ) {
	int l = t.l;
	int r = t.r;
	if( p >= l && p <= r ) return 0;
	else if( p < l ) {
		ll d = l-p;
		p += d;
		return d;
	}
	else {
		ll d = p-r;
		p -= d;
		return d;
	}
}

ll solve( int type ) {
	init();
	ll p = 0, s = 0;
	int begin = type == 1 ? 0 : 1;
	int end = type == 1 ? n-1 : n;
	for( int i = begin; i <= end; ++i )
		if( i & 1 ) {
			Triple tmp = *s1.begin();
			s1.erase(tmp);
			s2.erase(tmp);
			s += move(p, tmp);
		} else {
			Triple tmp = *s2.begin();
			s1.erase(tmp);
			s2.erase(tmp);
			s += move(p, tmp);
		}
	s += abs(p);
	return s;
}

int main() {
	_w = scanf( "%d", &n );
	for( int i = 1; i <= n; ++i )
		_w = scanf( "%d%d", L+i, R+i );
	printf( "%lld\n", max(solve(1), solve(2)) );
	return 0;
}
