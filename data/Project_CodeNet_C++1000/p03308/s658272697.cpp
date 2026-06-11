#include <math.h>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (int i = 0; i < (int)(n); ++i)
#define rrep(i,j,n) for(int i = (int)(j); i < (int)(n); i++)
#define mrep(i,n) for (int i = (int)(n-1); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define scout cout << fixed << setprecision(20) 
#define fi first
#define se second
ll INF = 1LL << 60;
ll mod = 1e9 + 7;
ll MAX=1e18;

int main() {
	int n; cin >> n;
	vint a(n);
	rep(i,n) cin >> a[i];
	sort(be(a));
	cout << a[n-1]-a[0] << endl;
}