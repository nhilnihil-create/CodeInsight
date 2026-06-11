#include <iostream>
typedef long long ll;
using namespace std;

ll x[200010], sum[200010];

int main() {
	int N;
	ll X;
	cin >> N >> X;
	sum[0]=0;
	for(int i=0; i<N; ++i){
		cin >> x[i];
		sum[i+1]=sum[i]+x[i];
	}
	int mxt=(N+1)/2;
	ll ans=X*(N+mxt)+sum[N]*5;
	for(int i=mxt-1; i>0; --i){
		ll now=X*(N+i)+(sum[N]-sum[N-i])*5;
		int mult=5;
		for(int j=N-i; j>0; j -= i){
			now += (sum[j]-sum[max(j-i, 0)])*mult;
			mult += 2;
		}
		if(now<ans) ans=now;
		else break;
	}
	cout << ans << endl;
	return 0;
}