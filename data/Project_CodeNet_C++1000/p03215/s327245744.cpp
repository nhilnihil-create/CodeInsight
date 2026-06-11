#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#define rep(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll mod = 1000000007;

ll rui[1010];

int main() {
	int n, K;
    cin >> n >> K;

    rep(i, n) {
        cin >> rui[i+1];
        rui[i+1] += rui[i];
    }
	
	ll ans = 0;
	for(int i = 53; i >= 0; i--) {
        ll p = 1LL<<i;
		int c = 0;
		rep(j, n) {
			for(int k = j; k < n; k++) {
				ll t = rui[k+1] - rui[j];
                ll y = ans + p;
				if((t & y) == y) {
                    c++;
                }
			}
		}
		if(c >= K) {
            ans += p;
        }
	}

	cout << ans << endl;
    return 0;
}