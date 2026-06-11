#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 1e5+10;
int N, M;
int P[MAX_N], Y[MAX_N];
string ans[MAX_N];

void solve()
{
	map<int,  vector<int>> v;
	for(int i=0;i<M;++i){
		v[P[i]].push_back(Y[i]);
	}
	for(auto& p : v) sort(p.second.begin(), p.second.end());
	for(int i=0;i<M;++i){
		string p = to_string(P[i]);
		while((int)p.length()<6) p="0"+p;
		int j = lower_bound(v[P[i]].begin(), v[P[i]].end(), Y[i])-v[P[i]].begin();
		string y = to_string(j+1);
		while((int)y.length()<6) y="0"+y;
		cout<<p+y<<'\n';
	}
}

int main()
{
	cin >> N >> M;
	for(int i=0;i<M;++i){
		cin >> P[i] >> Y[i];
	}
	solve();
	return 0;
}