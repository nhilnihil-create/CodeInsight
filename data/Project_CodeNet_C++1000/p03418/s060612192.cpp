#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

typedef long long ll;

int main(){
	int N,K;
	cin >> N >> K;

	ll ans = 0;
	for(int b=1; b<=N; b++){
		int p = N/b;
		int r = N%b;
		int md = max(b-K,0) * p;
		md += max(r-K+1,0);
		ans += md;
	}
	if(K==0)ans -= N;
	cout << ans << endl;

	return 0;
}