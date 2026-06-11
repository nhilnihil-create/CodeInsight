#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> p_int;
typedef pair<ll,ll> p_ll;
typedef tuple<ll,ll,ll> t3_ll;
int dx[] = {-1,0,1,0},dy[] = {0,1,0,-1};
int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
const ll inf = 1e9+7;

int main() {
	ll n,p;
	cin >> n >> p;
	ll waru = 2;
	ll x = p;
	unordered_map<ll,ll> insu;
	const ll aa = 1e7;
	bool arr[aa];
	for (int i = 0;i < aa;i++) {
		arr[i] = true;
	}
	for(int i = 2; i < aa; i++){
		if(arr[i]){
			for(ll j = 0; i * (j + 2) < aa; j++){
				arr[i *(j + 2)] = false;
			}
		}
	}
	for(int i = 2; i < aa; i++){
		if(arr[i]){
			while(x%i == 0) {
				x/=i;
				insu[i]++;
			}
		}
	}

	// while(x!=1) {
	// 	if (x % waru == 0) {
	// 		while(x%waru == 0) {
	// 			x/=waru;
	// 			insu[waru]++;
	// 		}
	// 	} else {
	// 		waru++;
	// 	}
	// // }
	// for (int i = 0;i < 1e6+10;i++) {
	// 	if (p%i == 0) {
	// 		insu[i] = 0;
	// 	}
	// }
	ll ans = 1;
	for (auto itr = insu.begin();itr != insu.end();itr++) {
		ans *= round(pow(itr->first,itr->second/n));
	}
	if (n == 1) {ans = p;}
	cout << ans << endl;
}