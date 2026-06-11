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

int n, x[1000], y[1000], t[2], d[32];

int main() {
	cin >> n;
	inc(i, n) { cin >> x[i] >> y[i]; }
	
	inc(i, n) { t[(x[i] + y[i]) % 2] = 1; }
	if(t[0] && t[1]) {
		cout << -1 << endl;
		return 0;
	}
	
	incII(i, 0, 30) { d[i] = 1 << (30 - i); }
	d[31] = 1;
	int m = (t[0] ? 32 : 31);
	
	cout << m << endl;
	inc(i, m) { cout << d[i] << (i == m - 1 ? "\n" : " "); }
	inc(i, n) {
		int X = y[i] + x[i];
		int Y = y[i] - x[i];
		
		int xp = 0, yp = 0, z;
		string s;
		inc(j, m) {
			z = 0;
			if(xp < X) { xp += d[j]; z |= 1; } else { xp -= d[j]; }
			if(yp < Y) { yp += d[j]; z |= 2; } else { yp -= d[j]; }
			s += "DRLU"[z];
		}
		
		cout << s << "\n";
	}
	
	return 0;
}
