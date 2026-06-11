#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int n; cin >> n;
	char s[n][n];
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			cin >> s[i][j];
		}
	}
	int ans = 0;
	for(int k = 0; k < n; k++){
		bool ok = true;
		for(int i = 0; i < n; i++){
			for(int j = i+1; j < n; j++){
				if(s[i][(j+k)%n] != s[j][(i+k)%n]) ok = false;
			}
		}
		if(ok) ans += n;
	}
	cout << ans << endl;
	return 0;
}