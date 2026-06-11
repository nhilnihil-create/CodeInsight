#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;

ll n, b, ca, cb, a[10005];
int main() {
	ll i;
	cin >> n;
	for(i=0; i<n; i++) scanf("%lld", &a[i]);
	for(i=0; i<n; i++) {
		scanf("%lld", &b);
		if(b < a[i]) ca += a[i]- b;
		else if(b > a[i]) cb += b-a[i] >> 1;
	}
	puts(cb>=ca ? "Yes" : "No");
	return 0;
}