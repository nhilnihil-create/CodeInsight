#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, cut, a[200008], aa[200008], ia[200008];

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	for(ll i = 2; i <= n; i++){a[i] += a[i-1];}
	
	cut = 1;
	for(ll i = 2; i <= n-2; i++){
		while(1){
			if(abs(a[i]-2*a[cut]) < abs(a[i]-2*a[cut+1])){aa[i] = cut; break;}
			else{cut++;}
		}
	}
	
	cut = n-1;
	for(ll i = n-2; i >= 2; i--){
		while(1){
			if(abs(a[n]-2*a[cut]+a[i]) < abs(a[n]-2*a[cut-1]+a[i])){ia[i] = cut; break;}
			else{cut--;}
		}
	}
	
	ll ans = a[n];
	for(ll j = 2; j <= n-2; j++){
		ll maxmax = max(max(a[aa[j]], a[j]-a[aa[j]]), max(a[ia[j]]-a[j], a[n]-a[ia[j]]));
		ll minmin = min(min(a[aa[j]], a[j]-a[aa[j]]), min(a[ia[j]]-a[j], a[n]-a[ia[j]]));
		ans = min(maxmax-minmin, ans);
		//cout << aa[j] << " " << j << " " << ia[j] << endl; 
	}
	
	cout << ans << endl;
	return 0;
}