#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k;
	cin >> n >> k;

	if (n % 2 == 0) {
		n /= 2;
		puts(n >= k ? "YES" : "NO");
	}
	else {
		n = (n + 1) / 2;
		puts(n >= k ? "YES" : "NO");
	}
	
	return 0;
}