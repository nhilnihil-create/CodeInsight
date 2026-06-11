// C - Linear Approximation
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	int N; cin>>N;
	vector<ll> B(N);
	for(int i=0; i<N; ++i){ cin>>B[i]; B[i] -= i+1; }
	sort(B.begin(), B.end());
	ll l = accumulate(B.begin()+N/2+(N%2), B.end(), 0LL);
	ll r = accumulate(B.begin(), B.begin()+N/2, 0LL);
	cout<< l-r <<endl;
}
