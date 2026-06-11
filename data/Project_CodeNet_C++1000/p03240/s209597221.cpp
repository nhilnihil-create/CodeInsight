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
	vector<int> x(n), y(n), h(n);
	rep(i,n) cin >> x[i] >> y[i] >> h[i];
	rep(cy, 101)rep(cx,101){
		int H = 0;
		rep(i,n){
			if(h[i]){
				H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
				break;
			}
		}
		bool ok = true;
		rep(i,n){
			int height = H - abs(x[i] - cx) - abs(y[i] - cy);
			chmax(height, 0);
			if(h[i] != height) ok = false;
		}
		if(ok){
			cout << cx << " " << cy << " " << H << endl;
			return 0;
		}
	}
	return 0;
}