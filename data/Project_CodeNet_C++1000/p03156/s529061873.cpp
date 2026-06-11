#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <random>
#include <chrono>
#include <tuple>
#include <random>

using namespace std;

typedef long long ll;
typedef long double ld;
#define fastInp cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(0);

const ll SIZE = 1e6 * 2 + 10, INF = 1e9 * 1e9 + 10;



int main()
{
    fastInp;

    ll n;
	cin >> n;
	ll a, b;
	cin >> a >> b;
	vector<ll> cnt(3);

	for (int i = 0; i < n; i++) {
		ll vl;
		cin >> vl;
		if (vl <= a) {
			cnt[0]++;
		} else if (vl > a && vl <= b) {
			cnt[1]++;
		} else {
			cnt[2]++;
		}
	}

	cout << min(min(cnt[0], cnt[1]), cnt[2]);
    return 0;
}