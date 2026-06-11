#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int D[55][55], c[505][505];
int cost0[55], cost1[55], cost2[55];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n, C;
	cin >> n >> C;
	rep(i,C)rep(j,C) cin >> D[i][j];
	rep(i,n)rep(j,n){
		cin >> c[i][j];
		--c[i][j];
	}
	rep(k,C){
		rep(i,n)rep(j,n){
			if((i+j)%3 == 0) cost0[k] += D[c[i][j]][k];
			if((i+j)%3 == 1) cost1[k] += D[c[i][j]][k];
			if((i+j)%3 == 2) cost2[k] += D[c[i][j]][k];
		}
	}
	int ans = 1e9;
	rep(i,C){
		rep(j,C){
			if(i == j) continue;
			rep(k,C){
				if(j == k) continue;
				if(k == i) continue;
				int cost = cost0[i] + cost1[j] + cost2[k];
				chmin(ans, cost);
			}
		}
	}
	cout << ans << endl;
	return 0;
}