#include <bits/stdc++.h>
#include <math.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vint;
#define rep(i,n) for (ll i = 0; i < (ll)(n); ++i)
#define rrep(i,j,n) for(ll i = (ll)(j); i < (ll)(n); i++)
#define mrep(i,n) for (ll i = (ll)(n-1); i >= 0; i--)
#define be(v) (v).begin(), (v).end()
#define dcout cout << fixed << setprecision(20) 
ll INF = 1LL << 60;
ll mod = 1e9 + 7;

int main(){
	int n; cin >> n;
	vector<int> s(n);
	int sum=0;
	rep(i,n) {
		cin >> s[i];
		sum=sum+s[i];
	}
	ll ans=INF;
	rep(i,n) {
		int ss=sum-(s[i]/2);
      if(ans>ss) ans=ss;
		//ans=min(ans,ss);
	}
	cout << ans << endl;
}