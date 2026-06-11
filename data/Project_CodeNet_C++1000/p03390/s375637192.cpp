#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int q; cin >> q;
for(;q--;){
	ll a, b;
	cin >> a >> b;
	ll kake = a * b - 1;
	ll root = max(0ll, ll(sqrt(kake))-2);
	while((root+1)*(root+1) <= kake) ++root;
	ll ans = root * 2 - 1;
	if(root * (root+1) > kake) --ans;
	if(a == b) ++ans;
	cout << ans << endl;
}
	return 0;
}
