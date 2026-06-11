#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
#define int ll
typedef pair<int,int> pii;
#define fi first
#define se second
#define Sort(a) sort(a.begin(),a.end())
#define rep(i,n) for(int i = 0;i < (n) ; i++) 
#define REP(i,n) for(int i = 0;i < (n) ; i++) 
#define MP(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define INF LLONG_MAX/4
#define INTINF INT_MAX/2
#define all(x) (x).begin(),(x).end()
#define debug(x) cerr<<#x<<": "<<x<<endl
#define debug_vec(v) cerr<<#v<<":";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T &a, T b){if(a < b){a = b;return true;}return false;}
template<class T> inline bool chmin(T &a, T b){if(a > b){a = b;return true;}return false;}
/*----------------------------------------------------------------*/
// const int MOD = 998244353;
const int MOD = 1000000007;


/*----------------------------------------------------------------*/
signed main(){


	int n,k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<pii> p;

	p.push_back(pii(1,0));
	pii now = pii(0,0);
	for(auto c:s){
		if(now.fi == c-'0'){
			now.se++;
		}else{
			p.push_back(now);
			now = pii(c-'0',1);
		}
	}
	p.push_back(now);
	if(now.fi == 0)p.push_back(pii(1,0));
	// for(auto x:p)cerr << x.fi << " , " << x.se << endl;
	
	if(p.size() <= 2*k+1){
		cout << s.size() << endl;
		return 0;
	}


	int cnt = 0;
	rep(i,2*k+1){
		cnt += p[i].se;
	}
	int maxi = cnt;
	int i = 0;
	while(2*k + 2*(i+1) < p.size()){
		cnt -= p[2*i].se;
		cnt -= p[2*i+1].se;
		cnt += p[2*k + 1 + 2*i].se;
		cnt += p[2*k + 2 + 2*i].se;
		chmax(maxi,cnt);
		i++;
	}
	cout << maxi << endl;


	
	return 0;
}
/*----------------------------------------------------------------*/

// g++ -std=gnu++17 code1.cpp
// sudo pip3 install --upgrade online-judge-tools
// rm -r -f test;oj dl https://code-festival-2017-qualb.contest.atcoder.jp/tasks/code_festival_2017_qualb_b
// rm -r -f test;oj dl https://abc124.contest.atcoder.jp/tasks/abc124_d