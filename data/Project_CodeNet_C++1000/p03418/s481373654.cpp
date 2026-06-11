#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	ll N,K;
	cin >> N >> K;
	ll ans = 0;
	for (int i = K+1; i <= N; ++i)
	{
		ans += (i-K) * (N / i) + max(ll(0),(N%i)-(K-1));
		if (K == 0) ans--;
		//cout << (i-K) * (N / i) + max(ll(0),(N%i)-(K-1)) << endl;
	}
	cout << ans << endl;
	return 0;
}