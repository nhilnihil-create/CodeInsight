#include<bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define repk(i,k,n) for (ll i = k; i < (ll)(n); ++i)
#define MOD 1000000007
typedef long long  ll;

using namespace std;

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N,K;
	cin >> N >> K;

	double ans=0;
	repk(i,1,N+1){
		int cnt = 0;
		int temp = i;
		while(temp < K){
			cnt++;
			temp *= 2;
		}
		// cout << cnt << endl;
		ans += pow(0.5 ,cnt);
	}

	ans /= N;

	cout << fixed << setprecision(15);
	cout << ans << endl;
	return 0;
}