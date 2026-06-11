#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9 + 7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}


signed main(){
	int N,A,B;
	cin >> N >> A >> B;
	if(A * B < N || N + 1 < A + B){
		cout << -1 << endl;
		return 0;
	}
	vector<int>ans[A];
	int yobun = N - A;
	REP(i,A){
		ans[i].push_back(1);
		int t = min(yobun,B-1);
		REP(j,t){
			ans[i].push_back(1);
		}
		yobun -= t;
	}
	vector<int>out(N);
	iota(ALL(out),1);
	int now = 0;
	REP(i,N){
		reverse(out.begin()+i,out.begin()+i+ans[now].size());
		i += (int)ans[now].size() - 1;
		now++;
	}
	REP(i,N){
		if(i)cout << " ";
		cout << out[i];
	}
	cout << endl;
}
