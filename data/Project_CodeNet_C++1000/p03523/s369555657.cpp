#include <bits/stdc++.h>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(a) (a).begin(),(a).end()
#define SORT(a) sort(all(a))
#define rSORT(a, i) sort(all(a),(i))

using ll = long long;
constexpr ll INF = 10000000000;
constexpr ll MOD = 1000000007;

using namespace std;

int main() {
	string s; cin >> s;

	string a = "AKIHABARA";
	ll ans = 0;
	ll se = 0;

	rep(i, 9) {
		if (a[i] == s[se]) {
			se++;
			continue;
		}
		else if (a[i] == 'A') {
			continue;
		}
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	if (se == s.size()) {
		cout<<"YES"<<endl;
	}
	else {
		cout << "NO" << endl;
	}
}

