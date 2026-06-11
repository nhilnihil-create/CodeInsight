#include <queue>
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
#include <map>
#include <functional>

#define rep(i, n) for(int i = 0; i < (n); i++)
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))



using namespace std;
typedef long long int ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pint;
const ll inf = (1LL << 60);



vector<pint> query;


ll N, C;
vector<pll> val, cval;
ll Clock[100005], Cclock[100005];
int main() {
	cin >> N >> C;
	ll v, x;

	rep(i, N) {
		cin >> x >> v;
		val.push_back({x, v});
	}
	
	rep(i, N) {
		cval.push_back({ C - val[N - 1 - i].first, val[N-1-i].second });
	}
	ll sum = 0, sumc = 0;
	rep(i, N) {

		sum += val[i].second;
		sumc += cval[i].second;

		if (i != 0) {
			Clock[i] = MAX(Clock[i - 1], sum - val[i].first);
			Cclock[i] = MAX(Cclock[i - 1], sumc - cval[i].first);
		}
		else {
			Clock[0] = MAX(0, sum - val[i].first);
			Cclock[0] = MAX(0, sumc - cval[i].first);
		}
		
	}

	ll rpos = 0;
	ll ans = MAX(Clock[N-1], Cclock[N-1]);

	for(rpos = 0; rpos < N - 1; rpos++){
		
		ans = MAX(ans, Clock[rpos] - val[rpos].first + Cclock[N - rpos - 2]);
		ans = MAX(ans, Cclock[rpos] - cval[rpos].first + Clock[N - rpos - 2]);

	}
	


	cout << ans << endl;
	return 0;
}