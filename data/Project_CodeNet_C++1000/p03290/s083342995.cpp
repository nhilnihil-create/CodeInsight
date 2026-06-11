#include <iostream>
#include <iomanip>
#include<vector>
#include <algorithm>
#include <queue>
#include<string>
#include <map>
#include <cmath>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <utility>
#include <set>
#include <bitset>
typedef long long ll;
typedef long double ld;

#define REP(i,s,n)for(ll i=s;i<(n);++i)
#define rep(i,n) REP(i,0,n)
using namespace std;
ll D, G;
vector<ll>P, C;

int main() {
	cin >> D >> G;
	P = C = vector<ll>(D);
	rep(i,D) {
		cin >> P[i] >> C[i];
	}
	ll ans = 1000;
	rep(bit,1<<D) {
		ll counter = 0;
		ll sum=0;
		rep(i,D) {
			if (bit&(1<<i)) {
				sum += (C[i] + P[i]*(i + 1) * 100);
				counter += P[i];
			}
			if (G<=sum) {
				ans = min(counter, ans);
				break;
			}
		}
		if (sum < G) {
			for (ll j = D - 1; 0 <= j; --j) {
				if (!(bit&(1 << j))) {
					ll tmpSum = G - sum;
					ll a = ((tmpSum - 1) / ((j + 1) * 100)) + 1;
					if (a <= P[j]) {
						counter += a;
						ans = min(counter, ans);
					}
				}
			}
		}
	}



	cout << ans << endl;
	return 0;
}