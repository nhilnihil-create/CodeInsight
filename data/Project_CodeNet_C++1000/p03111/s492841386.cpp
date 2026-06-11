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
ll n,A,B,C; 
vl vec;
ll dfs(ll cnt,ll a,ll b,ll c){
	if(cnt == n){
		if(min({a,b,c})==0)return MOD;
		else return abs(a - A) + abs(b - B) + abs(c - C) - 30;
	}
	ll ret0 = dfs(cnt + 1,a + vec[cnt],b,c) + 10;
	ll ret1 = dfs(cnt + 1,a,b + vec[cnt],c) + 10;
	ll ret2 = dfs(cnt + 1,a,b,c + vec[cnt]) + 10;
	ll ret3 = dfs(cnt + 1,a,b,c);
	return min({ret0,ret1,ret2,ret3});
}


signed main(){
	//cout << fixed << setprecision(10);
	cin >> n >> A >> B >> C;
	vec.resize(n);
	rep(i,0,n)cin >> vec[i];
	cout << dfs(0,0,0,0) << endl;




	return 0;
}