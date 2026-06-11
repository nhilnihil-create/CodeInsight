#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	int N, K;
	cin >> N >> K;
	ll h[N];
	rep(i,N) cin >> h[i];
	sort(h,h+N);
	ll minh = h[N-1] - h[0];
	rep(i, N-K+1){
		ll dh = h[i+K-1] - h[i];
		minh = min(minh, dh);
	}
	cout << minh << endl;
	return 0;
}
