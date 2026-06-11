#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	int n, m, k, x, y;
	cin >> n >> m >> k;
	cin >> x >> y;
	string p1, p2;
	cin >> p1 >> p2;
	
	int rx1 = 1, rx2 = n;
	int ry1 = 1, ry2 = m;
	
	char c;
//	cout << rx1 << " " << rx2 << " ";
//	cout << ry1 << " " << ry2 << endl;
	for (int i = k-1; i >= 0; --i) {
		// Player 2
		c = p2[i];
		if (c == 'U') {
			rx2 = min(n, rx2+1);
		} else if (c == 'D') {
			rx1 = max(1, rx1-1);
		} else if (c == 'L') {
		  	ry2 = min(m, ry2+1);
		} else if (c == 'R') {
			ry1 = max(1, ry1-1);
		}
		
		
		// Player 1
		c = p1[i];
		
		if (c == 'U') {
			rx1++;
		} else if (c == 'D') {
			rx2--;
		} else if (c == 'L') {
			ry1++;
		} else if (c == 'R') {
			ry2--;
		}
		
//		cout << rx1 << " " << rx2 << " ";
//		cout << ry1 << " " << ry2 << endl;
		if (ry2 < ry1 || rx2 < rx1) break;
	}
	
	
	if (rx1 <= x && x <= rx2 && ry1 <= y && y <= ry2) {
	  cout << "YES\n";
	} else {
	  cout << "NO\n";
	} 	
  	return 0;
}