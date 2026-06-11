#include "bits/stdc++.h"

#define REP(i,n) for(ll i=0;i<ll(n);++i)
#define RREP(i,n) for(ll i=ll(n)-1;i>=0;--i)
#define FOR(i,m,n) for(ll i=m;i<ll(n);++i)
#define RFOR(i,m,n) for(ll i=ll(n)-1;i>=ll(m);--i)
#define ALL(v) (v).begin(),(v).end()
#define UNIQUE(v) v.erase(unique(ALL(v)),v.end());
#define DUMP(v) REP(aa, (v).size()) { cout << v[aa]; if (aa != v.size() - 1)cout << " "; else cout << endl; }
#define INF 1000000001ll
#define MOD 1000000007ll
#define EPS 1e-9

const int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
const int dy[8] = { 0,1,1,1,0,-1,-1,-1 };


using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
ll max(ll a, int b) { return max(a, ll(b)); }
ll max(int a, ll b) { return max(ll(a), b); }
ll min(ll a, int b) { return min(a, ll(b)); }
ll min(int a, ll b) { return min(ll(a), b); }
///(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)(´・ω・`)///


int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	vi v(3);
	REP(i, s.size()) {
		v[s[i] - 'a']++;
	}
	sort(ALL(v));
	int n = s.size();
	if (n % 3 == 0) {
		if (v[0] == v[1] && v[1] == v[2])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else if (n % 3 == 1) {
		if (v[0] == v[1] && v[1]+1 == v[2])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
	else {
		if (v[0]+1 == v[1] && v[1] == v[2])cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
