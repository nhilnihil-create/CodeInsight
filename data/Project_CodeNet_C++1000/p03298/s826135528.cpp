#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <stack>
#include <functional>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> P;
typedef vector<P> vpl;
#define rep(i,n) for(ll i=0; i<(n); i++)
#define REP(i,a,b) for(ll i=(a); i<(b); i++)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
const int inf = 1<<30;
const ll linf = 1LL<<62;
const int MAX = 510000;
ll dy[8] = {0,1,0,-1,1,-1,1,-1};
ll dx[8] = {1,0,-1,0,1,-1,-1,1};
const double pi = acos(-1);
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
template<typename T1,typename T2> inline void print2(T1 a, T2 b){cout << a << " " << b << endl;}
template<typename T1,typename T2,typename T3> inline void print3(T1 a, T2 b, T3 c){
	cout << a << " " << b << " " << c << endl;
}
#define INT_MAX 1<<30
const ll mod = 1e9+7;

int main(){
	ll n; cin >> n;
	string s; cin >> s;
	vl l(26,0), r(26,0);
	string left = s.substr(0,n), right = s.substr(n,n);
	rep(i,n){
		l[left[i]-'a']++;
		r[right[i]-'a']++;
	}
	reverse(all(right));
	rep(i,26){
		if(l[i] != r[i]){
			cout << 0 << endl;
			return 0;
		}
	}
	ll ans = 0;
	rep(bit,1<<n){
		l = r;
		string t,u;
		rep(i,n){
			if(bit>>i & 1) t.push_back(s[i]);
			else u.push_back(s[i]);
		}
		ll m = t.size();
		vvl dp(n+1,vl(m+1,0));
		dp[0][0] = 1;
		rep(i,n){
			rep(j,m){
				if(i<j) break;
				if(right[i]==u[i-j]) dp[i+1][j] += dp[i][j];
				if(right[i]==t[j]) dp[i+1][j+1] += dp[i][j];
			}
		}
		ans += dp[n][m] * 2;
	}
	cout << ans << endl;
}