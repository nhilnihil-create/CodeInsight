#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int x3 = y1 - y2 + x2;
	int y3 = x2 - x1 + y2;
	int x4 = y1 - y2 + x1;
	int y4 = x2 - x1 + y1;
	cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
	return 0;
}