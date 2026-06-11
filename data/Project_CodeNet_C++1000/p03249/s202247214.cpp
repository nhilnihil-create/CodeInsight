#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

int main(){
	int N; cin >> N;
	vector<LL> D(N),dp(N,0);
	vector<int> s(N),sz(N,1),p(N,-1);
	map<LL,int> M;
	repp(i,0,N){
		cin >> D[i];
		M[D[i]] = i;
		s[i] = i;
	}
	sort(s.begin(),s.end(),[&](const int &i, const int &j){return D[i] > D[j];});
	repp(i,0,N-1){
		auto it = M.find(D[s[i]]-N+2+(sz[s[i]]-1)*2);
		if(it == M.end() || (*it).first >= D[s[i]]) return cout << -1 << endl, 0;
		p[s[i]] = (*it).second;
		dp[(*it).second] += sz[s[i]]+dp[s[i]];
		sz[(*it).second] += sz[s[i]];
	}
	if(D[s[N-1]] != dp[s[N-1]]) return cout << -1 << endl, 0;
	repp(i,0,N-1) cout << s[i]+1 << ' ' << p[s[i]]+1 << endl;
	return 0;
}
