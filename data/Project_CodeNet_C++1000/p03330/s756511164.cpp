#include <bits/stdc++.h>

using namespace std;
using ll =long long;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
#define SORT(a) sort((a).begin(),(a).end())
#define rSORT(a) reverse((a).begin(),(a).end())
#define For(i, a, b)    for(int i = (a) ; i < (b) ; ++i)
#define rep(i, n)       For(i, 0, n)
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
using P = pair<int,int>;
//Write From this Line

int main()
{
	int N, C;
	cin >> N >> C;
	vector<vector<int>> D(C,vector<int>(C));
	rep(i,C)rep(j,C) cin >> D[i][j];
	ll ans = 1e9;

	vector<vector<int>> color(N,vector<int>(N));
	rep(i,N){
		rep(j,N){
			cin >> color[i][j];
			color[i][j]--;
		}
	}

	vector<pair<long long, long long>> X(0),Y(0),Z(0);
	for(int k = 0; k < C; k++){
		int x = 0, y = 0, z = 0;
		rep(i,N)rep(j,N){
			if((i+j)%3 == 0) x += D[color[i][j]][k];
			if((i+j)%3 == 1) y += D[color[i][j]][k];
			if((i+j)%3 == 2) z += D[color[i][j]][k];
		}
		X.push_back({x,k});
		Y.push_back({y,k});
		Z.push_back({z,k});
	}
	SORT(X);
	SORT(Y);
	SORT(Z);
	rep(i,3)rep(j,3)rep(k,3){
		if(X[i].second == Y[j].second || X[i].second == Z[k].second || Y[j].second == Z[k].second) {
			continue;
		}
		ans = min(ans, X[i].first + Y[j].first + Z[k].first);
	}
	cout << ans << endl;
}
