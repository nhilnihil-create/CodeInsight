#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, n) for(ll i = 0; i < (ll)(n); ++i)
#define FOR(i, a, b) for(ll i=(a); i < (ll)(b); ++i)
template<class T> inline bool chmax(T& a, T b) { if(a < b){ a=b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if(a > b){ a=b; return 1; } return 0;}

int main(){
	string s,t;
	cin >> s >> t;
	
	int r[26],rr[26];
	REP(i,26){
		r[i] = -1;
		rr[i] = -1;
	}
	
	REP(i,s.size()){
		int ss = s[i] - 'a';
		int tt = t[i] - 'a';
		
		if(r[ss]==-1){
			r[ss] = tt;
		}else{
			if(r[ss]!=tt){
				cout << "No\n";
				return 0;
			}
		}
		
		if(rr[tt]==-1){
			rr[tt] = ss;
		}else{
			if(rr[tt]!=ss){
				cout << "No\n";
				return 0;
			}
		}
		
	}
	
	cout << "Yes\n";
	return 0;
	
	return 0;
}