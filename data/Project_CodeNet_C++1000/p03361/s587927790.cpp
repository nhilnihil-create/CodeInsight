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
	int h,w;
	cin >> h >> w;
	char s[h][w];
	rep(i,h)rep(j,w) cin >> s[i][j];
	bool ok=true;
	for(int i=1;i<h-1;i++) {
		for(int j=1;j<w-1;j++) {
			if(s[i][j]=='#') {
				if(s[i-1][j]=='.'&&s[i][j-1]=='.'&&s[i+1][j]=='.'&&s[i][j+1]=='.') ok = false;
			}
		}
	}
	if(ok) cout << "Yes" << endl;
	else cout << "No" << endl;
}