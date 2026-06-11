#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define ALL(v) (v).begin(),(v).end()
#define fi first
#define se second
template<typename A, typename B> inline bool chmax(A &a, B b) { if (a<b) { a=b; return 1; } return 0; }
template<typename A, typename B> inline bool chmin(A &a, B b) { if (a>b) { a=b; return 1; } return 0; }
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<int, pii> pip;
typedef pair<pll, pll> P;
const ll INF = 1ll<<30;
const ll MOD = 1000000007;
const double EPS = 1e-9;
const bool debug = 0;
//---------------------------------//

int main() {
	string S;
	cin >> S;
	int cnt[3] = {};
	map<char, int> mm;
	mm['a'] = 0; mm['b'] = 1; mm['c'] = 2;
	
	REP(i, S.size()) cnt[mm[S[i]]]++;
	
	sort(cnt, cnt + 3);
	
	if (cnt[2] - cnt[0] <= 1) puts("YES");
	else puts("NO");
	
	return 0;
}
