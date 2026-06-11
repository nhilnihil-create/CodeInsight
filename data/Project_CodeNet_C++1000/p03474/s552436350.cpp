#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int a,b; cin >> a >> b;
	string s; cin >> s;
	bool ok=true;
	rep(i,a+b+1) {
		if(i==a) {
			if(s[i]!='-') ok=false;
		}
		else {
			if('0'<=s[i]&&s[i]<='9') {}
			else ok=false;
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}