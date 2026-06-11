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

const int M = 200000;
int n, m, s[M], c[M][2];
bool f[M];
vector<int> g[M];

int main() {
	string ss;
	cin >> n >> m >> ss;
	inc(i, n) { s[i] = (ss[i] == 'A' ? 0 : 1); }
	inc(i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		g[a].PB(b);
		g[b].PB(a);
		c[a][s[b]]++;
		c[b][s[a]]++;
	}
	
	queue<int> q;
	inc(i, n) {
		if(c[i][0] == 0 || c[i][1] == 0) { f[i] = false; q.push(i); } else { f[i] = true; }
	}
	while(! q.empty()) {
		int v = q.front(); q.pop();
		for(auto && w: g[v]) {
			if(! f[w]) { continue; }
			int & r = c[w][s[v]];
			r--;
			if(r == 0) { f[w] = false; q.push(w); }
		}
	}
	
	cout << (count(f, f + n, true) > 0 ? "Yes" : "No") << endl;
	
	return 0;
}
