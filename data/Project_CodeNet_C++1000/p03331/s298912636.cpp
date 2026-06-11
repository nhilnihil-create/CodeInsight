#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int suu(char n) {
	return n-'0';
}

int main() {
	int n; cin >> n;
	string s = to_string(n);
	rrep(i,1,s.size()) {
		ll o=1;
		rep(j,i) {
			o*=10;
		}
		if(o==n) {
			cout << 10 << endl;
			return 0;
		}
	}
	int ans =0 ;
	rep(i,s.size()) {
		ans+=s[i]-'0';
	}
	cout << ans << endl;
}