// C - Linear Approximation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int N; cin>>N;
	vector<ll> B(N);
	for(int i=0; i<N; ++i){ cin>>B[i]; B[i] -= (i+1); }
	sort(B.begin(), B.end());
	ll r,l = r = B[N/2];
	if(N%2 == 0) --l;
	ll ans_l = 0, ans_r = 0;
	for(ll bi:B){
		ans_l += abs(bi - l);
		ans_r += abs(bi - r);
	}
	cout<< min(ans_l, ans_r) <<endl;
}
