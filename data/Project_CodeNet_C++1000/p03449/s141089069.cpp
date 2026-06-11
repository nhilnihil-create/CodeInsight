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

int main(){
	int n; cin >> n;
	vint a(n);
	rep(i,n) cin >> a[i];
	vint aa(n);
	rep(i,n) cin >> aa[i];
	int ans=0;
	int ame=0;
	rep(i,n) {
		rep(j,n) {
			if(j<=i) ame+=a[j];
			if(j>=i) ame+=aa[j];
			if(j==n-1){
				ans=max(ans,ame);
				ame=0;
			}
		}
	}
	cout << ans << endl;
}
