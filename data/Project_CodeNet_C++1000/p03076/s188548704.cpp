#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int a[5];
	rep(i,5) cin >> a[i];
	int dmax = 0;
	int idmax = 4;
	rep(i,5){
		int d = 10*ceil(0.1*a[i]) - a[i];
		if (d>dmax) {
			dmax = d;
			idmax = i;
		}
	}
	int tmp = a[idmax];
	a[idmax] = a[4];
	a[4] = tmp;

	int ans = 0;
	rep(i,4) {
		ans = 10*ceil((ans+a[i])/10.0);
	}
	ans += a[4];
	cout << ans << endl;

		return 0;
}
