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
#define rep(i,n) for (int i = 0; i < (n); ++i)
 
using namespace std;
 
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
int main () {
	int n;
    cin >> n;
	vector<ll> v(n);
	rep(i,n) {
		cin >> v[i];
	}
	ll ans = 0;
	int right = 0;
	ll s = 0;
	for (int left = 0; left < n; ++left) {
		while (right < n && (s ^ v[right]) == (s + v[right])) {
			s += v[right];
			++right;
		}
		ans += 1LL * right - 1LL * left;
		if (right == left)
			++right;
		else {
			s -= v[left];
		}
	}
	cout << ans << endl;
    return 0;
}