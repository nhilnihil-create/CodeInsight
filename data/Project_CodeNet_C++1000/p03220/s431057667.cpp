#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, T, A;
	cin >> N >> T >> A;
	double dtmin = 1000;
	int imin = -1;
	rep(i,N) {
		int h;
		cin >> h;
		double dt = abs((double)T-(double)h*0.006-A);
		if (dt<dtmin) {
			dtmin = dt;
			imin = i+1;
		}
	}
	cout << imin << endl;
	return 0;
}
