#include <bits/stdc++.h>
using namespace std;

int N, x, y, t, dt, dx, dy, oldx=0, oldy=0, oldt=0;

bool valid = true;
int main () {
	cin >> N;
	for(int i=1; i<=N; i++) {
		cin >> t >> x >> y;
		dt = t - oldt;
		dx = abs(x - oldx);
		dy = abs(y - oldy);
		if (dt>=dx+dy && (dt-dx-dy)%2==0) {
			oldt = t;
			oldx = x;
			oldy = y;
		} else {
			valid = false;
			break;
		}
	}
	if (valid) cout << "Yes" << endl;
	else cout << "No" << endl;
}
