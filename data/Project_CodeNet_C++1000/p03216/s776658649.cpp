#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <functional>
#include <unordered_set>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <ctime>
#include <cassert>
#include <queue>
#include <stack>
#include <bitset>

using namespace std;

const int N = 2e5 + 10;
long long a[N];
long long pref[N];
long long suff[N];
long long sum[N];



int main()
{
	::ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	string s;
	cin >> s;
	int q;
	cin >> q;
	while (q--) {
		int k;
		cin >> k;
		int cnt[2] = { 0,0 };
		long long pairs = 0;
		long long ans = 0;
		for (int i = 0; i < k; ++i) {
			if (s[i] == 'D') {
				cnt[0]++;
			} else if (s[i] == 'M') {
				cnt[1]++;
				pairs += cnt[0];
			} else if (s[i] == 'C') {
				ans += pairs;
			}
		}
		for (int i = k; i < n; ++i) {
			if (s[i - k] == 'D') {
				pairs -= cnt[1];
				--cnt[0];
			} else if (s[i - k] == 'M') {
				cnt[1]--;
			}

			if (s[i] == 'D') {
				cnt[0]++;
			}
			else if (s[i] == 'M') {
				cnt[1]++;
				pairs += cnt[0];
			}
			else if (s[i] == 'C') {
				ans += pairs;
			}
		}
		cout << ans << "\n";
	}
	return 0;
}