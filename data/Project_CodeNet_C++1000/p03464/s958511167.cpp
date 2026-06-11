#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll;

int main() {
	ll K,l,r,mn,mx,mA=0;
	cin >> K;
	vector<ll> A(K);
	rep(i,K) {
		cin >> A.at(i);
		mA = max(mA, A.at(i));
	}
	
	l=0, r=mA*K+10;
	while(r-l > 1) {
		ll m=(l+r)/2, t=m;
		rep(i,K) {
			t = t-t%A.at(i);
			if(t == 0)
				break;
		}

		if(t < 2)
			l = m;
		else
			r = m;
	}
	mn = r;

	l=0, r=mA*K+10;
	while(r-l > 1) {
		ll m=(l+r)/2, t=m;
		rep(i,K) {
			t = t-t%A.at(i);
			if(t == 0)
				break;
		}

		if(t <= 2)
			l = m;
		else
			r = m;
	}
	mx = l;

	if(mn > mx)
		cout << -1;
	else
		cout << mn << " " << mx;
	cout << endl;
}