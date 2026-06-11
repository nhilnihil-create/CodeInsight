#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(a,b,n) for(ll a = (ll)(b); a < (ll)(n); a++)
#define mrep(i,n) for (ll i = (ll)(n); i > 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main() {
	ll n,h; cin >> n >> h;
	vint a(n); vint b(n);
	rep(i,n) cin >> a[i] >> b[i];
	sort(be(a)); sort(be(b));
	reverse(be(a)); reverse(be(b));
	ll A=a[0];
	ll ans=0;
	ll cut=0;
	rep(i,n) {
		if(A<b[i]) {
			cut++;
			ans+=b[i];
			if(ans>=h) {
				cout << cut << endl;
				return 0;
			}
		}
		else break;
	}
	cut+=(h-ans+A-1)/A;
	cout << cut << endl;
}