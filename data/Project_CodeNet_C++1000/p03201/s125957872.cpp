#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<tuple>

#define DIV 1000000007
#define TE 2e5
using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	int N; cin >> N ;
	vector<ll> a(N);
	map<ll, int> cnt;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}

	vector<ll> twos(35);
	twos[0] = 1;
	for (int i = 1; i < 35; i++) {
		twos[i] = twos[i - 1] * 2;
	}

	sort(a.begin(), a.end(), greater<ll>());
	ll ans = 0, M = 34;
	for (int i = 0; i < N; i++) {
		for (int j = M; j >= 0; j--) {
			if (twos[j] > 2 * a[i]) {
				M--;
			}

			if (cnt[a[i]] > 0 && cnt[twos[j] - a[i]] > 0) {
				if (a[i] == twos[j] - a[i] && cnt[a[i]] < 2)continue;
				cnt[a[i]]--, cnt[twos[j] - a[i]]--;
				ans++;
				//cout << a[i] << " " << twos[j] - a[i] << endl;
				break;
			}

			if (twos[j] <= a[i]) {
				break;
			}
		}
	}

	cout << ans << endl;
}