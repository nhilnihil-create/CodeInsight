#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <sstream>
#include <utility>
#include <deque>
#include <numeric>
#include <map>
#include <stack>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define INF 1000000000000

using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

int main () {
    int N;
	ll K;
	cin >> N >> K;
	vector<ll> A(N);
	rep(i,N) cin >> A[i];
	vector<int> count(40,0);
	rep(i,40)
		rep(j,N)
			if ((A[j] >> i) & 1LL)
				count[i]++;
	ll ans = 0;
	rep(i,40) {
		ll x = K + 1;
		if (((x >> i) & 1LL) == 0)
			continue;
		x &= ~(1LL << i);
		for (int j=0; j < i; ++j) {
			if (count[j] > N - count[j]) {
				x &= ~(1LL << j);
			} else {
				x |= (1LL << j);
			}
		}
		ll cur = 0;
		rep(j,N)
			cur += x ^ A[j];
		ans = max(ans, cur);
	}
	cout << ans << endl;
    return 0;
}