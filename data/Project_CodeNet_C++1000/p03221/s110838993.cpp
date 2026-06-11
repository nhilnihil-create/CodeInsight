#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using ll=long long;
using pll=pair<ll,ll>;

#define fi first
#define se second
#define pb push_back
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define MOD 1000000007

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

int main() {
	int N,M;
	cin >> N >> M;
	vector<int> P(M),Y(M);
	vector<vector<pii>> v(N, vector<pii>());
	rep(i,M) {
		cin >> P[i] >> Y[i];
		P[i]--;
		v[P[i]].pb(pii(Y[i],i));
	}
	rep(i,N) {
		sort(v[i].begin(), v[i].end());
	}
	vector<pii> t(M);
	rep(i,N) {
		for(int j=0; j<v[i].size(); j++) {
			t[v[i][j].se] = pii(i+1, j+1);
			//cout << setfill('0') << right << setw(6) << P[i]+1 << setfill('0') << right << setw(6) << j+1 << endl;
		}
	}
	rep(i,M) {
			cout << setfill('0') << right << setw(6) << t[i].fi << setfill('0') << right << setw(6) << t[i].se << endl;
	}


  return 0;
}
