#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main(){
	int h, w, d, in, q;
	cin >> h >> w >> d;
	map<int, int> y;
	map<int, int> x;
	rep(i, h){
		rep(j, w){
			cin >> in;
			in--;
			y[in] = i;
			x[in] = j;
		}	
	}
	cin >> q;
	vector<int> a(h*w);
	rep(i, d){
		int yn = y[h*w-1-i];
		int xn = x[h*w-1-i];
		int ym = yn;
		int xm = xn;
		int dsum = 0;
		for(int j=0; j>=0; j++){
			if(h*w-1-i-j*d < 0) break;
			ym = yn;
			xm = xn;
			yn = y[h*w-1-i-j*d];
			xn = x[h*w-1-i-j*d];
			dsum += abs(ym - yn) + abs(xm - xn);
			a.at(h*w-1-i-j*d) = dsum;
//			cout << h*w-1-i-j*d << ' ' << ym << ' ' << yn  << ' ' << xm << ' ' << xn << ' ' << dsum << endl;
		}
	}
	rep(i, q){
		int ia, ib;
		cin >> ia >> ib;
		ia--; ib--;
		int ans = a.at(ia);
		ans -= a.at(ib);
		cout << ans << endl;
	}
	return 0;
}