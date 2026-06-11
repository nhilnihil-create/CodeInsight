#include <bits/stdc++.h>
using namespace std;

typedef long long   signed int LL;
typedef long long unsigned int LU;

#define incID(i, l, r) for(int i = (l)    ; i <  (r); i++)
#define incII(i, l, r) for(int i = (l)    ; i <= (r); i++)
#define decID(i, l, r) for(int i = (r) - 1; i >= (l); i--)
#define decII(i, l, r) for(int i = (r)    ; i >= (l); i--)
#define  inc(i, n) incID(i, 0, n)
#define inc1(i, n) incII(i, 1, n)
#define  dec(i, n) decID(i, 0, n)
#define dec1(i, n) decII(i, 1, n)

#define inII(v, l, r) ((l) <= (v) && (v) <= (r))
#define inID(v, l, r) ((l) <= (v) && (v) <  (r))

#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define PQ priority_queue

#define  ALL(v)  v.begin(),  v.end()
#define RALL(v) v.rbegin(), v.rend()
#define  FOR(it, v) for(auto it =  v.begin(); it !=  v.end(); ++it)
#define RFOR(it, v) for(auto it = v.rbegin(); it != v.rend(); ++it)

template<typename T> bool   setmin(T & a, T b) { if(b <  a) { a = b; return true; } else { return false; } }
template<typename T> bool   setmax(T & a, T b) { if(b >  a) { a = b; return true; } else { return false; } }
template<typename T> bool setmineq(T & a, T b) { if(b <= a) { a = b; return true; } else { return false; } }
template<typename T> bool setmaxeq(T & a, T b) { if(b >= a) { a = b; return true; } else { return false; } }
template<typename T> T gcd(T a, T b) { return (b == 0 ? a : gcd(b, a % b)); }
template<typename T> T lcm(T a, T b) { return a / gcd(a, b) * b; }

// ---- ----

const int M = 100000;
LL n, c, x[M + 2], v[M + 2];

LL a[M + 2], b[M + 2];
LL f() {
	LL s = 0;
	inc1(i, n) {
		s += v[i] - abs(x[i] - x[i - 1]) * 2;
		a[i] = max(s, a[i - 1]);
	}
	
	s = 0;
	dec1(i, n) {
		s += v[i] - abs(x[i] - x[i + 1]);
		b[i] = max(s, b[i + 1]);
	}
	
	LL ans = 0;
	incII(i, 0, n) { setmax(ans, a[i] + b[i + 1]); }
	
	return ans;
}

void flip() {
	inc(i, (n + 2) / 2) {
		swap(x[i], x[n + 1 - i]);
		swap(v[i], v[n + 1 - i]);
	}
	inc(i, n + 2) { x[i] = c - x[i]; }
}

int main() {
	cin >> n >> c;
	x[0] = 0; v[0] = 0;
	inc1(i, n) { cin >> x[i] >> v[i]; }
	x[n + 1] = c; v[n + 1] = 0;
	
	LL ans = 0;
	setmax(ans, f()); flip();
	setmax(ans, f());
	
	cout << ans << endl;
	
	return 0;
}
