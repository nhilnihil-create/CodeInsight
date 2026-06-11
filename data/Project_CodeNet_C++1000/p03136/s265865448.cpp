#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<int> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	vint l(n);
	rep(i,n) cin >> l[i];
	sort(be(l));
	reverse(be(l));
	int a=0;
	rrep(i,1,n) a+=l[i];
	if(a>l[0]) cout << "Yes" << endl;
	else cout << "No" << endl;
}