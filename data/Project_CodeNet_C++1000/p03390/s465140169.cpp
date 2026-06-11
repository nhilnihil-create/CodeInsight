#include <iostream>
#include <cstdio>
#include <algorithm>
#define inf (1e10) + 2
typedef long long ll;
using namespace std;
//const ll inf = 10000000000000000002ll;
ll A, B;
ll get_max(ll l1, ll l2, ll r1, ll r2) {
	//cout<<l1<<' '<<l2<<' '<<r1<<' '<<r2<<"******"<<endl;
	//if(r2 - r1 != l2 - l1) cout<<"****"<<endl;
	if(l1 > l2 || r1 > r2) return 0;
	if(l1 > r1) swap(l1, r1), swap(l2, r2);
	ll mid = (r2 - l1) / 2;
	ll maxx = max(l1 * r2, l2 * r1);
	for(ll i = mid - 10; i <= mid + 10; ++i) {
		ll num1 = l1 + i, num2 = r2 - i;
		if(num1 < l1 || num1 > l2 || num2 < r1 || num2 > r2) continue;
		maxx = max(maxx, num1 * num2); 
	} 
	mid = (l2 - r1) / 2;
	for(ll i = mid - 10; i <= mid + 10; ++i) {
		ll num1 = l2 - i, num2 = r1 + i;
		if(num1 < l1 || num1 > l2 || num2 < r1 || num2 > r2) continue;
		maxx = max(maxx, num1 * num2); 
	} 	
//	cout<<maxx<<endl;
	return maxx;
}
bool check(ll k) {
	//cout <<k<<"*****************"<<endl; 
	if(k < A && k < B) return get_max(1, k, 1, k) < A * B;
	//cout<<"__________________"<<endl;
	if(k < A && k >= B) 
	return get_max(1, B - 1, k - B + 2, k) < A * B &&
	get_max(1, k - B + 1, B + 1, k + 1) < A * B;
	if(B - 1 == k + 1 - A) return get_max(1, A - 1, B + 1, k + 1) < A * B &&
	get_max(A + 1, k + 1, 1, B - 1) < A * B;
	//cout<<"***************"<<endl;
	if(B - 1 > k + 1 - A) return get_max(A + 1, k + 1, 1, k - A + 1) < A * B &&
	get_max(k - B + 2, A - 1, k - A + 2, B - 1) < A * B && get_max(1, k - B + 1, B + 1, k + 1) < A * B;
	//cout<<"******************"<<endl;
	return get_max(k - B + 3, k + 1, 1, B - 1) < A * B && get_max(A + 1, k - B + 2, B + 1, k - A + 2) < A * B
	&& get_max(1, A - 1, k - A + 3, k + 1) < A * B; 
}
int main() {
	int Q;
	//A = 11, B = 4;
	//cout<<check(12)<<endl;
	//cout<<get_max(1, 3, 4, 6)<<endl; 
	scanf("%d", &Q);
	while(Q--) {
		scanf("%lld%lld", &A, &B);
		if(A < B) swap(A, B);
		ll l = 0, r = inf;
		ll ans = 0;
		while(l <= r) {
			//cout<<l <<' '<<r<<"^^^^^^^^^^^^^"<<endl;
			ll mid = (l + r) >> 1;
			if(check(mid)) l = mid + 1, ans = mid;
			else r = mid - 1;
		}
		printf("%lld\n", ans);
	}	
	return 0;
}