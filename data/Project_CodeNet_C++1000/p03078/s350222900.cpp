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



int main()
{
	cin.tie(0); ios_base::sync_with_stdio(false);
	int x, y, z, k;
	cin >>x >>y >>z >>k;
	VL a(x), b(y), c(z);
	rep(i, x) cin >>a[i];
	rep(i, y) cin >>b[i];
	rep(i, z) cin >>c[i];
	
	VL ab; ab.reserve(x*y+100);
	rep(i, x) rep(j, y) ab.push_back(a[i] + b[j]);
	sort(all(ab), greater<ll>());
	if(sz(ab) > k) ab.resize(k);
	VL abc; ab.reserve(sz(ab)* k);
	sort(all(c), greater<ll>());
	rep(i, sz(ab)) rep(j, z) {
		abc.push_back(ab[i] + c[j]);
	}
	sort(all(abc), greater<ll>());
	rep(i, k) cout << abc[i] <<"\n";

	return 0;
}
