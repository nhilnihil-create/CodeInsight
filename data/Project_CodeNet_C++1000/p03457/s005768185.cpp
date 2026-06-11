#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<int, int> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int curX = 0, curY = 0, curT = 0;
	rep(i,n){
		int t, x, y;
		cin >> t >> x >> y;
		int dx = abs(curX - x), dy = abs(curY - y);
		if((dx + dy > t - curT) || ((t-curT)-(dx+dy))%2 == 1){
			cout << "No" << endl;
			return 0;
		}
		curX = x; curY = y; curT = t;
	}
	cout << "Yes" << endl;
	return 0;
}