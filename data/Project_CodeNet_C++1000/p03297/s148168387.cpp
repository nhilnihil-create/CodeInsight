#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define REP(i,n) for(int i=0; i<int(n); i++)
#define FOR(i,m,n) for(int i=int(m); i<int(n); i++)
#define ALL(obj) (obj).begin(),(obj).end()
#define VI vector<int>
#define VP vector<pair<int,int>>
#define VPP vector<pair<int,pair<int,int>>>
#define VLL vector<long long>
#define VVI vector<vector<int>>
#define VVLL vector<vector<long long>>
#define VC vector<char>
#define VS vector<string>
#define VVC vector<vector<char>>
#define VB vector<bool>
#define VVB vector<vector<bool>>
#define fore(i,a) for(auto &i:a)
typedef pair <int, int> P;
template<typename T> using min_priority_queue = priority_queue<T, vector<T>, greater<T>>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int  INF = 1 << 30;
const ll INFL = 1LL << 60;
const ll mod = 998244353;

ll gcd(ll a, ll b) {
	if (b == 0)return a;
	else return gcd(b, a%b);
}


bool solve(ll a, ll b, ll c, ll d) {
	if (b > a || b > d)return false;
	if (b <= c)return true;
	ll g = gcd(b, d);

	ll e = (b - a % g + g - 1) / g * g;

	e += a % g;
	e -= g;
	if (e > c)return false;
	return true;

}


int main() {

	int t;
	cin >> t;
	REP(qi,t) {
		ll a, b, c, d;
		cin >> a >> b >> c >> d;
		cerr << "========";
		if (solve(a, b, c, d))cout << "Yes" << endl;
		else cout << "No" << endl;


	}


}