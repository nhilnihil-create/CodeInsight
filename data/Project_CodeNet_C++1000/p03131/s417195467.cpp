#include<bits/stdc++.h>
using namespace std;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define ll long long

int main() {
	ll k, a, b;
	scanf("%lld%lld%lld", &k, &a, &b);
	ll biscuits = 1;
	if (b - a <= 2)
		return cout << k + 1, 0;

	while (k > 0) {
		if (biscuits >= a) {
			if (k >= 2){
				biscuits = biscuits -a + b;
				k-=2;
			}else
				biscuits++, k--;
		} else {
			biscuits++;
			k--;
		}
	}
	cout << biscuits << endl;
	return 0;
}
