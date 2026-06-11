#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,j,n) for(int i = (int)(j); i < (int)(n); i++)
#define mrep(i,n) for (int i = (int)(n); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20)
ll INF = 1LL << 60;
ll mod = 1e9 + 7;
ll modn = 998244353;

int main() {
	int x,y; cin >> x >> y;
	if(x%y==0) {
		cout << -1 << endl;
		return 0;
	}
	for(ll i=x;i<=1e18;i++) {
		if(i%y!=0) {
			cout << i << endl;
			return 0;
		}
      	i+=x;
	}
	cout << -1 << endl;
}