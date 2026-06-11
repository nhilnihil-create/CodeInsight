#include <iostream>
#define ll long long
using namespace std;

ll next_minimum(ll key){
	ll g=key, dsum=0;
	while(g>0){
		dsum += g%10;
		g /= 10;
	}
	int d=1;
	bool flag=1;
	ll res=key, nsum=dsum;
	while(flag){
		ll c=key, sum=dsum;
		for(int i=0; i<d; ++i){
			sum -= c%10;
			c /= 10;
		}
		flag=(c>0);
		for(int i=0; i<d; ++i){
			c *= 10;
			c += 9;
			sum += 9;
		}
		if(res*sum>c*nsum){
			res=c;
			nsum=sum;
		}
		++d;
	}
	return res;
}

int main() {
	int K;
	cin >> K;
	ll ans=0;
	for(int i=0; i<K; ++i){
		ans=next_minimum(ans+1);
		cout << ans << endl;
	}
	return 0;
}