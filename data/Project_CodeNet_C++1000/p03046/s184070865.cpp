#include <bits/stdc++.h>
using namespace std;
 
#define ll long long 
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ii pair<int,int>
#define vii vector<ii>
#define vi vector<int>

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
 
 
 //1. x^x = 0
 //2. x^0 = x
 //3. xor(1,2,3..., 2^M - 1) = 0 for M >= 2
 //xor(1,2,3,4,5,,7) = 6

//(1 2 . . . 2^m-1 without k)  k (2^m-1 ... 2 1 ) k

void solve(){
	ll m,k; cin >> m >> k;
	if(k==0){
		FOR(i,pow(2,m)) cout << i << " " << i << " "; 
	} else if(m == 1){
		cout << -1;
	} else if(pow(2,m) <= k){
		cout << -1;
	} else{
		FOR(i,pow(2,m)){
			if(i==k) continue;
			else cout << i << " ";
		}
		cout << k << " ";
		for(int i = pow(2,m)-1; i>=0; --i){
			if(i == k) continue;
			else cout << i << " ";
		}
		cout << k;
	}
}
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 
