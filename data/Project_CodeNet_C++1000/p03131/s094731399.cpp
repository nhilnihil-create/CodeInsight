#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll K, A, B;
	cin >> K >> A >> B;
	ll ans = K+1;
	if (A<B) {
		K -= A-1;
	}
	ll tmp = A;
	while (K>1) {
		tmp += B-A;	
		K -= 2;
	}
	if (K == 1) tmp++;
	ans = max(ans, tmp);
	cout << ans << endl;
return 0;
}
