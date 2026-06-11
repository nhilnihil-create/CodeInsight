#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,A,B;
	cin >> N >> A >> B;

	int ans = 0;
	repk(i,1,N+1){
		int isum = 0;
		int now = i;
		while(now > 0){
			isum += now % 10;
			now /= 10;
		}
		// cout << i << ": " << isum << endl;
		if(isum >= A && isum <= B){
			ans += i;
		}
	}

	cout << ans << endl;
	return 0;
}