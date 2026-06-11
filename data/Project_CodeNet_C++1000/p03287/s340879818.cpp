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
#define rep(i,n) for (long long i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	ll N, M;
    cin >> N >> M;
	map<ll,ll> mp;
	ll S = 0;
	ll tmp;
	rep (i,N) {
		cin >> tmp;
		tmp = tmp % M;
		S = (S + tmp) % M;
		mp[S]++;
	}
	ll ans = mp[0];
	for (auto p : mp) {
		ll n = p.second;
		ans += n*(n-1)/2;
	}
	cout << ans << endl;
    return 0;
}