#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int main() {
	ll n;
	scanf("%lld",&n);
	ll a[n];
	scanf("%lld",&a[0]);
	for(int i=1;i<n;i++){
		scanf("%lld",&a[i]);
		a[0]=__gcd(a[0],a[i]);
		
	}
	printf("%lld\n",a[0]);
}
