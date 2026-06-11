#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	int n;
	cin >> n;
	int f[n][5][2];
	int p[n][11];
	rep(i,n)rep(j,5)rep(k,2) cin >> f[i][j][k];
	rep(i,n)rep(j,11) cin >> p[i][j];
	int ans = -INF-1;
	for(int bit = 1; bit < (1 << 10); bit++){
		int tmp = 0;
		vector<int> work(10, 0);
		for(int i = 0; i < 10; i++){
			if(1&bit>>i) work[i] = 1;
		}
		for(int i = 0; i < n; i++){
			int co = 0;
			for(int j = 0; j < 10; j++){
				if(work[j]&&f[i][j/2][j%2])  co++;
			}
			tmp += p[i][co];
		}
		chmax(ans, tmp);
	}
	cout << ans << endl;
}