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
	int n; cin >> n;
	vector<string> a(n);
	rep(i,n) cin >> a[i];
	rrep(i,1,n) {
		if(a[i-1][a[i-1].size()-1]!=a[i][0]) {
			cout << "No" << endl;
			return 0;
		}
		for(int j=i-1;j>=0;j--) {
			if(a[i]==a[j]) {
				cout << "No" << endl;
				return 0;
			}
		}
	}
	cout << "Yes" << endl;
}