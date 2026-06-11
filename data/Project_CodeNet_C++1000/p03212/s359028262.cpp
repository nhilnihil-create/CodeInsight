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
ll ans=0;
ll n;

void dfs(string s){
	if(s.size()>9)return;
	ll m=stol(s);
	if(m>n)return;
	map<char,int> mp;
	rep(i,0,s.size()){
		mp[s[i]]++;
	}
	if(mp.size()==3)ans++;
	dfs(s+'3');
	dfs(s+'5');
	dfs(s+'7');
	return;
}

string p(ll i,string s){
	if(i==0)s.push_back('3');
	else if(i==1)s.push_back('5');
	else s.push_back('7');
	return s;
}

signed main(){
	//cout << fixed << setprecision(10);
	cin>>n;
	if(n<357){
		cout<<0<<endl;
		return 0;
	}
	dfs("3");
	dfs("5");
	dfs("7");
	cout << ans << endl;

	return 0;
}