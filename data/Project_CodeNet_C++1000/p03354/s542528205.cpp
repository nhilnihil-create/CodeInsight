#include <bits/stdc++.h>

#define rep2(x,fr,to) for(int (x)=(fr);(x)<(to);(x)++)
#define rep(x,to) for(int (x)=0;(x)<(to);(x)++)
#define repr(x,fr,to) for(int (x)=(fr);(x)>=(to);(x)--)
#define all(c) (c).begin(),(c).end()
#define sz(v) (int)(v).size()

using namespace std;
typedef long long ll; typedef vector<int> VI; typedef pair<int,int> pii;
const int MD = (int)1e9 + 7; typedef vector<ll> VL;
void dbg(){ cerr << "\n"; }  template <class T, class ...T2> void dbg(const T& fst, const T2&...rst){ cerr << fst << ": "; dbg(rst...); }
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
	bool same(int a, int b){ return find(a) == find(b); }
};

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int n, m;
	cin >>n >>m;
	VI p(n);
	rep(i, n){ cin >>p[i]; p[i]--;}
	UF ufa(n);
	rep(i, m){
		int x, y;
		cin >>x >>y;
		ufa.unite(x-1, y-1);
	}
	int ans = 0;
	rep(i, n){
		if(ufa.same(i, p[i])) ans++;
	}
	cout <<ans <<"\n";
	return 0;
}
