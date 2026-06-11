#include <iostream>
#include <algorithm>
#include <vector>
#include<string>
#include <set>
#include <map>
#include <queue>
#include <limits.h>
#include <bitset>

using namespace std;

#define rip(i, n, s) for (int i = (s);i < ( int )( n ); i++)
#define all(a) (a).begin(), (a).end()
typedef long long ll;

int main() {
	int n, k;
	cin >> n >> k;
	vector<ll> da(n);
	rip(i, n, 0) {
		cin >> da[i];
	}
	vector<ll> li(n*(n + 1) / 2);
	int co = 0;
	rip(i, n, 0) {
		li[co] = da[i];
		co++;
		rip(j, n, i + 1) {
			li[co] = li[co - 1] + da[j];
			co++;
		}
	}
	vector<bitset<40>> arr(n*(n + 1) / 2);
	rip(i, n*(n + 1) / 2, 0) {
		arr[i] = bitset<40>(li[i]);
	}
	int m = n * (n + 1) / 2;
	bitset<40> ans, now;
	now.set(39);
	rip(i, 40, 0) {
		ans = ans | now;
		int gg = 0;
		rip(j, m, 0) {
			bitset<40> hoge = arr[j] & ans;
			if (hoge==ans) {
				gg++;
			}
		}
		if (gg < k) {
			ans = ans ^ now;
		}
		now >>= 1;
	}
	ll answer = ans.to_ullong();
	cout << answer << endl;
}