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

LL n, x, d[200001], INF = 8e18;

LL f(int k) {
	LL sum = n * x;
	bool f = true;
	inc(i, n) { if(! f) { break; }
	inc(j, k) {
		if(k * i + j == n) { f = false; break; }
		LL l = n - 1 - (k * i + j);
		sum += (i == 0 ? 5 * d[l] + x : (2 * i + 3) * d[l]);
	}
	}
	
	return sum;
}

int main() {
	cin >> n >> x;
	inc(i, n) { cin >> d[i]; }
	
	int l = 1, h = n;
	while(h - l >= 3) {
		int m1 = l + (h - l) / 3 * 1;
		int m2 = l + (h - l) / 3 * 2;
		
		if(f(m1) >= f(m2)) { l = m1; } else { h = m2; }
	}
	
	LL ans = INF;
	incII(i, l, h) { setmin(ans, f(i)); }
	
	cout << ans << endl;
	
	return 0;
}

