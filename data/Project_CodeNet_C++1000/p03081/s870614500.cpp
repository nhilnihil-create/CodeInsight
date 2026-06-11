#include <bits/stdc++.h>
#define X first
#define Y second
typedef long long ll;
using namespace std;

const int MOD = 1e9 + 7;
const ll INF = 1e18;

int n, q;
string s;
char t[200010];
char d[200010];

int main () {

	cin >> n >> q;
	cin >> s;
	
	for (int i = 0; i < q; i ++) {
		cin >> t[i] >> d[i];
	}
	
	int lo = 0, hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int pos = mid, da = 0;
		for (int i = 0; i < q; i ++) {
			if (s[pos] == t[i]) {
				if (d[i] == 'L') pos --;
				else pos ++;
			}
			
			if (pos >= n) {
				da = 1;
				break;
			}
		}
		
		if (da) hi = mid;
		else lo = mid+1;
	}
	int sol = lo;
	//cout << sol << endl;
	
	lo = 0, hi = n;
	while (lo < hi) {
		int mid = (lo + hi) / 2;
		int pos = mid, da = 0;
		for (int i = 0; i < q; i ++) {
			if (s[pos] == t[i]) {
				if (d[i] == 'L') pos --;
				else pos ++;
			}
			
			if (pos < 0) {
				da = 1;
				break;
			}
		}
		
		if (da) lo = mid+1;
		else hi = mid;
	}
	
	sol -= lo;
	cout << sol;

	return 0;
}