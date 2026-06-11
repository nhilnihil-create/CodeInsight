#include <bits/stdc++.h>

#define ll long long int
#define ull unsigned long long int
#define IO ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);


using namespace std;

const int INF = 1e9 + 7;
const int N = 1e5+5;

int main() {

	IO; 

	int p, n;
	cin >> p >> n;
	
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	
	if (p>= n) {
		cout << 0 << endl;
		return 0;
	}
	
	sort(a.begin(), a.end());
	vector<int> s;
	
	for (int i = 1; i < n; ++i) {
		s.push_back(abs(a[i] - a[i-1]));
	}
	sort(s.rbegin(), s.rend());
	ll ans = 0;
	for (int i = p-1; i < (int) s.size(); ++i) {
		ans += s[i];
	}
	
	cout << ans << endl;
	
	
}

