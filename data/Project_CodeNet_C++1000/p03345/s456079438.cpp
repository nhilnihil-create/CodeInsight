#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i< (n); i++)
using ll = long long;
using namespace std;

int main(){
	ll A, B, C, K;
	cin >> A >> B >> C >> K;
	ll ans;
	if (K%2==0) ans = A-B;
	else ans = B-A;
	if (abs(ans)>1e+18) cout << "Unfair" << endl;
	else cout << ans << endl;
	return 0;
}
