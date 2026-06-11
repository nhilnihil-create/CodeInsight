#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi = vector<int>;
using vvi = vector<vector<int>>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
#define all(x) x.begin(),x.end()
#define rep(i,j,n) for (int i = j; i < (int)(n); i++)
#define _GLIBCXX_DEBUG
#define MOD 1000000007
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//name[i][j]-> vvl name(i,vl(j))
//map<int,int>mp
//余りを切り上げる =>  (a + b - 1) / b 

signed main(){
	int n; cin>>n;
	map<char,int> mp;
	rep(i,0,n){
		string s; cin>>s;
		mp[s[0]]++;
	}
	vector<char> vec={'M','A','R','C','H'};
	vi c={0,0,1,1,1};
	ll ans=0;
	do{
		ll cnt=1;
		rep(i,0,5){
			if(c[i]==0) continue;
			cnt*=mp[vec[i]];
		}
		ans+=cnt;
	}while(next_permutation(all(c)));
	cout<<ans;
	return 0;
}