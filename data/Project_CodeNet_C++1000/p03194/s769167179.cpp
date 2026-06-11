#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define rep(i,n) FOR(i,0,n)
typedef long long ll;
map<int,int> ma;

int main(){
	ll n,p;
	cin >> n>>p;
	ll ans = 1;
	// factor
	ll a=2;

	if (n==1) {
		cout << p << endl;
		return 0;
	}
	while (p>=a*a) {
		if (p%a == 0) {
			ma[a]++;
			p/=a;
		} else {
			a++;
		}
	}
	if (p!=1) {
		ma[p]++;
	}

	for (auto &num : ma) {
		while (num.second >= n) {
			ans *= num.first;
			num.second -= n;
		}
	}
	cout << ans << endl;
}

