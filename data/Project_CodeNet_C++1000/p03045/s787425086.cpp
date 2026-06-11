#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int x=(fr);x<(to);x++)
#define rep(x,to) for(int x=0;x<(to);x++)
#define repr(x,fr,to) for(int x=(fr);x>=(to);x--)
#define all(c) c.begin(),c.end()
#define sz(v) (int)v.size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
typedef vector<ll> VL; const int MD = (int)1e9 + 7;
void dbg(){ cerr << "\n"; } template <typename T,typename ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
template <class T, class T2> void amax(T& a,T2 b){ if(a < b) a = b;}

struct UF{
	vector<int> p;
	UF() {}
	UF(int n) : p(n, -1) {}
	int find(int a){ return p[a] < 0 ? a : p[a] = find(p[a]); }
	bool unite(int a, int b) {
		a = find(a); b = find(b);
		if(a == b) return false;
		if(-p[a] < -p[b]) swap(a, b);
		p[a] += p[b]; p[b] = a;
		return true;
	}
	bool root(int a){ return p[a] < 0; }
	bool same(int a, int b){ return find(a) == find(b); }
	int size(int a){ return -p[find(a)]; }
};

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	UF uf(n);
	rep(i, m){
		int x, y, z;
		cin >>x >>y >>z;
		uf.unite(x-1, y-1);
	}
	int ans = 0;
	rep(i, n) ans += uf.root(i);
	cout <<ans <<"\n";
	return 0;
}
