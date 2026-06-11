#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)




	
void solve() {

	int n;
	cin >> n;
	string a, b, c;
	cin >> a >> b >> c;
	int cnt = 0;
	for(int i = 0; i < n; i++) {
		if(a[i] == b[i] && b[i] == c[i]) {
		}
		else {
			if(a[i] == b[i] || b[i] == c[i] || a[i] == c[i]) {
				cnt++;
			}
			else {
				cnt += 2;
			}
		}
	}
	cout << cnt << "\n";
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}