#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define REP(i,n) for(int i=1;i<=n;i++)
typedef long long ll;

int main(){
	ll k,a,b;
	cin >> k >> a >> b;
	if(a  + 2 >= b){
		cout << k + 1 << endl;
		return 0;
	} else if (k <= a - 1){
		cout << k + 1 << endl;
	}
	ll ans = a;
	ans += (b-a) * ((k-a+1) / (2)) + (k-a+1) % 2;
	cout << ans << endl;
	return 0;
}