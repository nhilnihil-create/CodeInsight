#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,m;
	cin >> n >> m;
	vector<ll> x(m);
	rep(i,m) cin >> x[i];
	sort(x.begin(),x.end());
	vector<ll> sa(m-1);
	rep(i,m-1) sa[i] = x[i+1] - x[i];
	sort(sa.rbegin(),sa.rend());
	if(n > m){
		cout << 0 << endl;
		return 0;
	}
	ll ans = x[m-1] - x[0];
	rep(i,n-1) ans -= sa[i];
	cout << ans << endl;
    return 0;
}

