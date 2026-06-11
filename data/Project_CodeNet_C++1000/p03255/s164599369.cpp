#include <iostream>
using namespace std;
typedef unsigned long long ll;

ll N,X,x[200010] = {0};
int main(){
	cin >> N >> X;
	ll sum = 0;
	for(int i=1;i<=N;i++){
		cin >> x[i];
		x[i] += x[i-1];
	}
	ll ans = 2e18;
	for(int i=1;i<=N;i++){
		ll s = 2,pre = (N+i)*X;
		int id = N;
		while(id>0){
			pre += (2*s+1)*(x[id]-x[max(id-i,0)]);
			if(id!=N) s++;
			id -= i;
		}
		ans = min(ans,pre);
	}
	cout << ans << endl;
}