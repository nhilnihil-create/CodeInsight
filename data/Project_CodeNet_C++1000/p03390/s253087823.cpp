#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll q, a, b;
int main() {
	scanf("%lld", &q);
	while(q--) {
		scanf("%lld%lld", &a, &b);
		if(a > b) swap(a, b);
		if(a == b) cout << a+a-2 << endl;
		else if(a+1 == b) cout << a+a-2 << endl;
		else  {
			ll c = sqrt(a*b) + 10;
			while(c*c >= a*b) --c;
			if(c*(c+1) >= a*b) cout << c+c-2 << endl;
			else cout << c+c-1 << endl;
		}
	}
	return 0;
}