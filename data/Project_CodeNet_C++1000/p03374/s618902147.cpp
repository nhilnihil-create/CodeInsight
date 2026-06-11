#include <iostream>
#define ll long long
using namespace std;

ll x[100010], v[100010];
ll cw1[100010], cw2[100010], acw1[100010], acw2[100010];

int main() {
	int N;
	ll C;
	cin >> N >> C;
	for(int i=0; i<N; ++i){
		cin >> x[i] >> v[i];
	}
	ll sum=0;
	for(int i=0; i<N; ++i){
		sum += v[i];
		cw1[i+1]=max(cw1[i], sum-x[i]);
		cw2[i+1]=max(cw2[i], sum-x[i]*2);
	}
	sum=0;
	for(int i=N-1; i>=0; --i){
		sum += v[i];
		acw1[i+1]=max(acw1[i+2], sum-(C-x[i]));
		acw2[i+1]=max(acw2[i+2], sum-(C-x[i])*2);
	}
	ll ans=0;
	for(int i=0; i<=N; ++i){
		ans=max(ans, cw2[i]+acw1[i+1]);
		ans=max(ans, cw1[i]+acw2[i+1]);
	}
	cout << ans << endl;
	return 0;
}