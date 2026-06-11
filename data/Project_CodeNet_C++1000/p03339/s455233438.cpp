#include <bits/stdc++.h> 
using namespace std;

typedef long long ll;

int main() {	
	int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> e(n + 2);
    vector<int> w(n + 2);
    for (int i = 1; i <= n; ++i) {
		e[i] = e[i - 1];
		if (s[i - 1] == 'W') {
			e[i]++;
		}
	}
	 for (int i = n; i > 0; --i) {
		w[i] = w[i + 1];
		if (s[i - 1] == 'E') {
			w[i]++;
		}
	}
	int ans = 1e9 + 7;
	for (int i = 1; i <= n; ++i) {
		ans = min(ans,e[i - 1] + w[i + 1]);
	}
	cout << ans;
}
