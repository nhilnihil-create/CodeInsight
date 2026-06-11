#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MAX_N = 310, MAX_Q = 1e5+2;
int H, W, D;
int A[MAX_N][MAX_N];
int Q;
int L[MAX_Q], R[MAX_Q];

ll dist[MAX_N*MAX_N];

void solve()
{
	map<int, pair<int,int>> loc;
	for(int i=1;i<=H;++i)for(int j=1;j<=W;++j){
		loc[A[i][j]] = make_pair(i, j);
	}
	const int LAST = H*W;
	for(int i=D;i<=LAST;++i){
		 dist[i] = dist[i-D] + (abs(loc[i].first-loc[i-D].first)+abs(loc[i].second-loc[i-D].second));
	}
	for(int i=0;i<Q;++i){
		cout << dist[R[i]]-dist[L[i]] << '\n';
	}
}

int main()
{
	cin >> H >> W >> D;
	for(int i=1;i<=H;++i)for(int j=1;j<=W;++j){
		cin >> A[i][j];
	}
	cin >> Q;
	for(int i=0;i<Q;++i) cin >> L[i] >> R[i];
	solve();
	return 0;
}