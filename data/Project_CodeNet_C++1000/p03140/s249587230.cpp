#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i, s, n) for (int i = (s); i < (n); i++)
#define RFOR(i, s, n) for (int i = (n) - 1; i >= (s); i--)
#define REP(i, n) FOR(i, 0, n)
#define RREP(i, n) RFOR(i, 0, n)
#define ALL(a) a.begin(), a.end()
const long long MOD = 1e9+7, INF = 1e18;
template<class T>inline bool CHMAX(T&a,T b){if(a<b){a=b;return true;}return false;}
template<class T>inline bool CHMIN(T&a,T b){if(a>b){a=b;return true;}return false;}



signed main(){
	int N;
	cin >> N;
	string A,B,C;
	cin>>A>>B>>C;
	int ans = 0;
	REP(i,N){
		set<int>st;
		st.insert(A[i]);
		st.insert(B[i]);
		st.insert(C[i]);
		if(st.size()==1)continue;
		else if(st.size()==2)ans++;
		else ans+=2;
	}
	cout<<ans<<endl;
}