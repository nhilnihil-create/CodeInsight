#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
using namespace std;
typedef long long ll;

template <typename T>
bool chmin(T & a, const T & b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	string S;
	cin >> n;
	cin >> S;

	int l = 0;
	int r = count(all(S), '.');
	int ans = r;
	rep(i, n) {
		if (S[i] == '.') {
			r--;
		}
		else {
			l++;
		}
		chmin(ans, r + l);
	}

	dunk(ans);
	
	return 0;
}
