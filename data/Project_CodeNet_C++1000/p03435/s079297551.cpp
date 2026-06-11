#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)
#define inv(n, a) for(int i = 0; i < n; i++) cin >> a[i]
#define MOD 1000000007
#define INF 1e7
#define LINF 1e15
#define Yes cout << "Yes" << endl
#define No cout << "No" << endl
typedef long long ll;
typedef long double ld;
using Graph = vector<vector<int>>;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
// 'a' = 97 'z' = 122 => 'a' = 0 'z' = 25

int ok(vector<int> v){
	rep(i, 2){
		for(int j = i+1; j < 3; j++){
			if (v[i] != v[j])
				return 0;
		}
	}
	return 1;
}

int main() {
    Graph c(3, vector<int>(3));
	rep(j, 3)
		inv(3, c[j]);
	vector<int> v(3);
	rep(i, 2){
		for(int j = i+1; j < 3; j++){
			rep(k, 3){
				v[k] = c[k][i] - c[k][j];
			}
			if (!ok(v)){
				No;
				return 0;
			}
		}
	}
	rep(i, 2){
		for(int j = i+1; j < 3; j++){
			rep(k, 3){
				v[k] = c[i][k] - c[j][k];
			}
			if (!ok(v)){
				No;
				return 0;
			}
		}
	}
	Yes;
}
