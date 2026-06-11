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

const int mxN = 1e5;

void solve(){
	int n,k; string s; cin >> n >> k >> s;
	
	vector<int> seg0, seg1;
	
	// find lengths of all 0 segments and 1 segments
	int zeros = 0, ones = 0;
	int cnt = 0;
	for(char c : s){
		++cnt;
		if(c == '0' && cnt == s.size()) seg0.pb(zeros+1);
		else if(c == '0') ++zeros;
		else if(zeros) seg0.pb(zeros), zeros = 0;
		
		if(c == '1' && cnt == s.size()) seg1.pb(ones+1);
		else if(c=='1') ++ones;
		else if(ones) seg1.pb(ones), ones = 0;
	}
	
	//debugv(seg0);
	//debugv(seg1);
		
	while(seg0.size() < mxN) seg0.pb(0);
	while(seg1.size() < mxN) seg1.pb(0);
	
	int fin_ans = 0, cur_ans = 0;
	
	// if we start with 0 segment
	if(s[0] == '0'){
		FOR(k) cur_ans += seg0[i] + seg1[i];
		fin_ans = cur_ans;
		FOR(i,k,(1e5)/2 + 7){
			int low0 = i-k;
			int low1 = i-k-1;
			// guarantee low1 to be 0
			if(low1 == -1) low1 = 1e5 - 1; 
			cur_ans += seg0[i] + seg1[i] - seg0[low0] - seg1[low1];
			fin_ans = max(fin_ans, cur_ans);
		}
	} else{
		FOR(k) cur_ans += seg0[i] + seg1[i];
		cur_ans += seg1[k];
		fin_ans = cur_ans;
		FOR(i,k,(1e5)/2 + 7){
			int high0 = i;
			int high1 = i+1;
			int low0 = i-k;
			int low1 = i-k;
			cur_ans += seg0[high0] + seg1[high1] - seg0[low0] - seg1[low1];
			fin_ans = max(fin_ans, cur_ans);
		}
	}
	
	cout << fin_ans;
}
 
 
 //5 1
//00010

//seg0: 3 1 0 0 

//seg1: 1 0 0 0
 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	solve();
	return 0;
}
 
