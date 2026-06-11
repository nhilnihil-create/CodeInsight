#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <cstring>
#include <queue>
#include <assert.h>
#include <cmath>
#include <deque>
#include <unordered_map>
using namespace std;
using ll = long long;
using ld = long double;
const int mod = 1e7+7;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	ll N; cin>>N;
	ll cnt = (ll)log10(N)/1ll;
	ll test = 1ll*pow(10, cnt)-1;
	int ret = 0;
	for(ll i=9; i>=0; i--) {
		if(i*pow(10, cnt)+test<=N) {
			ret = i;
			break;
		}
	}
	cout << ret+9*cnt << '\n';
	return 0;	
}