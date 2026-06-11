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
ll dp[55][55][5000];

signed main(){
	//cout << fixed << setprecision(10);
	string s; cin>>s;
	int n=s.size();
	ll ans=0,cnt=0;
	rep(i,0,n){
		if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T')cnt++;
		else{
			chmax(ans,cnt);
			cnt=0;
		}
	}
	chmax(ans,cnt);
	cout<<ans<<endl;
	 
	return 0;
}