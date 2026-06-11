#include<bits/stdc++.h>
//g++ -std=c++11 

using namespace std;
typedef long long ll;

#define rep(i,n) for (long long i = 0; i < (n); ++i)
#define DIV 1000000007 //10^9+7

vector<ll> S[15];
ll P[15];

int main(){
	ll N, M;
	cin >> N >> M;

	rep(i, M) {
		ll k;
		cin >> k;
		rep(j, k) {
			ll s;
			cin >> s;
			s--;
			S[i].push_back(s);
		}
	}

	rep(i, M) {
		cin >> P[i];
	}

	ll ans = 0;
	rep(state, (1<<N)) {
		bool ok = true;
		rep(i, M) {
			ll num = 0;
			for(ll s: S[i]) {
				if((state>>s)&1) {
					num++;
				}
			}

			if(num%2 != P[i]) {
				ok = false;
			}
		}
		if(ok) {
			ans++;
		}
	}

	cout << ans << endl;
}
