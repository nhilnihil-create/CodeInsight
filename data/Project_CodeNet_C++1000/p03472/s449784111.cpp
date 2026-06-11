#include<bits/stdc++.h>
#include<numeric>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i <= (ll)(n); ++i)
#define MAX 500000001000000000
#define MOD 1000000007
typedef long long  ll;

using namespace std;

ll ans;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll N,H;
	cin >> N >> H;

	vector<ll> a(N),b(N);
	ll amax = 0, amaxindex = 0;
	rep(i, N){
		cin >> a[i] >> b[i];
		if(a[i] > amax){
			amax = a[i];
			amaxindex = i;
		}
	}

	sort(b.begin(),b.end(),greater<ll>());
	rep(index,N){
		if(b[index]>=amax){
			H -= b[index];
			ans++;
			if(H <= 0){
				cout << ans << endl;
				return 0;
			}
		}
		else{
			break;
		}
	}

	if(H % amax == 0){
		ans += H / amax;
	}
	else{
		ans += H / amax + 1;
	}

	cout << ans << endl;
	
	return 0;
}