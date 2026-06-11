#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,z,w;
	cin >> n >> z >> w;
	vector<ll> a(n);
	rep(i,n){
		cin >> a[i];
	}
	ll ans;
	if(n == 1){
		ans = abs(a[0] - w);
	}else{
		ans = max(abs(a[n-1]-w), abs(a[n-1] - a[n-2]));
	}
	cout << ans << endl;
    return 0;
}