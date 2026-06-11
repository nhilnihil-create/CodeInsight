#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MAX_N = 1e5+10;

int N, M;
int P[MAX_N], Y[MAX_N];
string ans[MAX_N];

void solve(){
	map<int,vector<int>> v;
	for(int i=0; i<M; ++i) v[P[i]].push_back(Y[i]);
	for(auto& p:v) sort(p.second.begin(), p.second.end());
	for(int i=0; i<M; ++i){
		int j=lower_bound(v[P[i]].begin(), v[P[i]].end(), Y[i])-v[P[i]].begin();
		printf("%06d%06d\n", P[i], j+1);
	}
}

int main(){
	cin>>N>>M;
	for(int i=0; i<M; ++i) cin>>P[i]>>Y[i];
	solve();
}