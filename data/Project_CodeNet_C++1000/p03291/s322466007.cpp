#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main(){
	string s;
	cin >> s;
	int n = s.size();
	vector<int> a(n,0),aq(n,0),c(n,0),cq(n,0);
	for(int i(1);i<n;++i){
		a[i] = a[i-1];
		aq[i] = aq[i-1];
		if(s[i-1] == 'A') a[i]++;
		if(s[i-1] == '?') aq[i]++;
	}
	for(int i(n-2);i >= 0; --i){
		c[i] = c[i+1];
		cq[i] = cq[i+1];
		if(s[i+1] == 'C') c[i]++;
		if(s[i+1] == '?') cq[i]++;
	}
	ll ans(0), num(pow(10,9)+7);
	vector<ll> pow3(n+10);
	rep(i,n+1){
		if(i == 0) pow3[i] = 1;
		else pow3[i] = 3 * pow3[i-1] % num;
	}
	for(int i(1);i < n-1; ++i){
		if(s[i] == 'B' | s[i] == '?'){
			ll ap = a[i] * pow3[aq[i]] % num;
			if(aq[i] >= 1) ap += (aq[i] * pow3[aq[i]-1]) % num;
			ll cp = c[i] * pow3[cq[i]] % num;
			if(cq[i] >= 1) cp += (cq[i] * pow3[cq[i]-1]) % num;
			ans += (ap * cp) % num;
			ans %= num;
		}
	}
	cout << ans << endl;
	return 0;
}