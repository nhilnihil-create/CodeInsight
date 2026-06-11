#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for (auto& x: a)
 
// debug templates 
#define debug(x)       cerr<< #x <<" : "<< x << endl;
#define debuga(A,N)    cerr<< #A <<" : [";for(int i = 0; i<N;i++) cerr<<A[i]<<" "; cerr<<"]\n";
#define debuga2(A,N,M) cerr<< #A << " : \n"; for(int i=0;i<N;i++){cerr<<"[";for(int j=0;j<M;++j) cerr<<A[i][j]<<" ";cerr<<"]\n";}
#define debugp(p)      cerr<< #p <<" : "<<"("<<(p).first<<","<<(p).second<<")\n";
#define debugv(v)      cerr<< #v <<" : "<<"[";for(int i = 0; i< (v).size(); i++) cerr<<v[i]<<" "; cerr<<"]\n";
#define debugv2(v)     cerr<< #v << " : \n"; for(int i=0;i<v.size();i++){cerr<<"[";for(int j=0;j<(v[0].size());++j) cerr<<v[i][j]<<" ";cerr<<"]\n";}
#define debugs(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin(); itr!=m.end();itr++) cerr<<*itr<<" "; cerr<<"]\n";
#define debugm(m)      cerr<< #m <<" : [ "; for(auto itr = m.begin();itr!=m.end(); itr++) cerr<<"("<<itr->first<<","<<itr->second<<") ";cerr<<"]\n";
 

//gcd(a,b,c) = gcd(gcd(a,b),c)

//4 8 2 6
//f 4 4 2 2
//b 2 2 2 6
//--> 2
void solve(){
	int n; cin >> n;
	int a[n];
	FOR(n) cin >> a[i];
	int f[n], b[n];
	f[0] = a[0];
	FOR(i,1,n) f[i] = gcd(a[i],f[i-1]);
	b[n-1] = a[n-1];
	for(int i = n-2; i >= 0; --i) b[i] = gcd(a[i],b[i+1]);
	ll final_ans = 1;
	FOR(n){
		ll ans;
		int l = i-1, r = i+1, gcd_l, gcd_r;
		if(l < 0) gcd_l = inf, gcd_r = b[r];
		else if(r>=n) gcd_r = inf, gcd_l = f[l];
		else gcd_l = f[l], gcd_r = b[r];
		
		if(gcd_l == inf) ans = gcd_r;
		else if(gcd_r == inf) ans = gcd_l;
		else ans = gcd(gcd_l,gcd_r);
		final_ans = max(final_ans,ans);
	}
	cout << final_ans;
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 
