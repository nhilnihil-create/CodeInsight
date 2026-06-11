#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll n, a[200008], aa[200008], ia[200008];

int main(){
	cin >> n;
	for(ll i = 1; i <= n; i++){cin >> a[i];}
	for(ll i = 2; i <= n; i++){a[i] += a[i-1];}
	
	for(ll i = 2; i <= n-2; i++){
		ll high = i-1;
		ll low = 1;
		while(high-low > 1){
			ll mid = (high+low)/2;
			if(a[i]-2*a[mid] < 0){high = mid;}
			else{low = mid;}
		}
		if(abs(a[i]-2*a[low]) < abs(a[i]-2*a[high])){aa[i] = low;}
		else{aa[i] = high;}
	}
	
	for(ll i = 2; i <= n-2; i++){
		ll high = n-1;
		ll low = i+1;
		while(high-low > 1){
			ll mid = (high+low)/2;
			if(a[n]-2*a[mid]+a[i] < 0){high = mid;}
			else{low = mid;}
		}
		if(abs(a[n]-2*a[low]+a[i]) < abs(a[n]-2*a[high]+a[i])){ia[i] = low;}
		else{ia[i] = high;}
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