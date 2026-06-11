#include <iostream>
#include <stdio.h>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
#include <stack>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define mod ((ull)1e9+7)
#define MAX ((ull)1e6)

ll pmod(ll n, ll p){
	ll m=n%mod;
	if(p==1) return m;
	ll ans=pmod((m*m)%mod, p/2)%mod;
	if(p%2==1) ans=(ans*m)%mod;
	return ans;
}

ll binom(ll n, ll k){
	ll a=1, b=1;
	for(ll i=0; i<k; i++){
		a=((a%mod)*((n-i)%mod))%mod;
		b=((b%mod)*((k-i)%mod))%mod;
	}
	return (a*pmod(b, mod-2))%mod;
}

ll find_mid(ll a[], double v, int b, int e){
	while(e-b>1){
		if((double)a[(b+e)/2]<v) b=(b+e)/2;
		else e=(b+e)/2;
	}
	if(abs((double)a[b]-v)<abs((double)a[e]-v)) return a[b];
	else return a[e];
}

int main(){
	int n;
	cin >> n;
	ll a[n];
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	cout << a[n-1] << " " << find_mid(a, a[n-1]/2.0, 0, n-2) << endl;
	return 0;
}