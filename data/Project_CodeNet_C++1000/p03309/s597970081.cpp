// C - Linear Approximation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int N; cin>>N;
	vector<ll> B(N);
	for(int i=0; i<N; ++i){ cin>>B[i]; B[i] -= (i+1); }
	sort(B.begin(), B.end());
	ll r = B[N/2];
	ll ans = 0;
	for(ll bi:B) ans += abs(bi - r);
	cout<< ans <<endl;
}
