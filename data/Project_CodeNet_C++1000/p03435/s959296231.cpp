#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int c[3][3];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	rep(i,3)rep(j,3) cin >> c[i][j];
	for(int a1 = 0; a1 <= 100; ++a1){
		vector<int> a(3), b(3);
		a[0] = a1;
		rep(j,3) b[j] = c[0][j] - a[0];
		a[1] = c[1][0] - b[0];
		a[2] = c[2][0] - b[0];
		bool ok = true;
		rep(i,3)rep(j,3){
			if(a[i]+b[j] != c[i][j]) ok = false;
		}
		if(ok){
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}