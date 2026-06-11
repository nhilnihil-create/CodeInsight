//#include "pch.h"
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <limits.h>
#include <string>
#include <deque>
#include <cmath>
#include <bitset>

using namespace std;
typedef long long ll;
typedef pair<int, int> P;

#define rip(i, n, s) for (int i = (s);i < (int)( n ); i++)
#define mpa make_pair
#define all(a) (a).begin(), (a).end()

ll Sqrt(ll x,ll st){
	ll ok = 0, ng = st + 2;
	while(ng - ok > 1){
		ll mi = (ok + ng)/2;
		if(x < mi * mi){
			ng = mi;
		}
		else{
			ok = mi;
		}
	}
	return ok;
}

ll solve(){
	ll a,b;
	cin >> a >> b;
	if (a > b){
		swap(a, b);
	}
	ll k = Sqrt(a * b - 1, b), ans = k * 2;
	if (a == b){
		return ans;
	}
	if (k * (k + 1) >= a * b){
		ans--;
	}
	ans--;
	return max((ll)0, ans);
}

int main(){
	int q;
	cin >> q;
	vector<ll> ans(q);
	rip(i,q,0){
		ans[i] = solve();
	}
	rip(i, q, 0){
		printf("%lld\n", ans[i]);
	}
}