#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (long long i = j; i < (long long)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	string s; cin>>s;
	int n=s.size();
	if(s[0]!='A'){
		cout<<"WA"<<endl;
		return 0;
	}
	int cnt=0;
	rep(i,2,n-1){
		if(s[i]=='C')cnt++;
	}
	
	if(cnt!=1){
		cout<<"WA"<<endl;
		return 0;
	}
	set<char> k;
	rep(i,0,26) k.insert('A'+i);
	rep(i,0,n){
		if(i==0)continue;
		if(k.count(s[i]) && s[i]!='C'){
			cout<<"WA"<<endl;
			return 0;
		}
	}
	cout<<"AC"<<endl;
		
	
	return 0;
}