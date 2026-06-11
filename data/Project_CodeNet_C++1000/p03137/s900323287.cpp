#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)

using namespace std;
using LL = long long;

int main(){
	int N, M;
	cin >> N >> M;
	vector<int> X(M), dist(M-1);
	rep(i,M) cin >> X[i];
	sort(X.begin(),X.end());
	rep(i,M-1) dist[i]=X[i+1]-X[i];
	sort(dist.begin(),dist.end());
	int ans=0;
	rep(i,M-N) ans+=dist[i];
	cout << ans << endl;

	return 0;
}