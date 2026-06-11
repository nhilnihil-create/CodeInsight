#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll n,h;
	cin >> n >> h;
	vector<ll> a(n);
	vector<ll> b(n);
	rep(i,n) cin >> a[i] >> b[i];
	sort(a.rbegin(),a.rend());
	sort(b.rbegin(),b.rend());
	ll count = 0;
	rep(i,n){
		if(h <= 0) break;
		if(a[0] < b[i]){
			h -= b[i];
			count++;
		}
	}
	if(h > 0){
		count += (h + a[0] - 1) / a[0];
	}
	cout << count << endl;
    return 0;
}

