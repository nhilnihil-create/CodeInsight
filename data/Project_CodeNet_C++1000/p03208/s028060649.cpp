#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;

int main(){
	int N,K;
	cin >> N >> K;
	vector<int> h(N);
	rep(i,N){cin >> h[i];}
	sort(h.begin(),h.end());
	ll D;
	ll ans = 1e18;
	for(int i=0; i<N-K+1; i++){
		D = h[i+K-1] - h[i];
		ans = min(ans, D);
	}
	

	cout << ans << endl;
	return 0;
}