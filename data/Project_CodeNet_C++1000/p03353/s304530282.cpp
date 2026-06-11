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
const ll MOD = 1000000007;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
//(a+b-1)/b
//priority_queue<ll, vector<ll>, greater<ll>> q;

signed main(){
	//cout << fixed << setprecision(10);
	string s; cin>>s;
	ll n=s.size();
	ll k; cin>>k;
	set<string> st;
	rep(i,0,s.size()){
		string t;
		rep(j,i,min(i+6,n)){
			t.push_back(s[j]);
			st.insert(t);
		}
	}
	ll cnt=1;
	for(string c:st){
		if(cnt==k){
			cout<<c<<'\n';
			return 0;
		}
		cnt++;
	}



	return 0;
}