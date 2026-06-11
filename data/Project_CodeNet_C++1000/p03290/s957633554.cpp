#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>

#define DIV 1000000007

using namespace std;
using ll = long long;
using ldb = long double;

int main() {
	ll D, G; cin >> D >> G;
	vector<pair<ll, ll>> pro(D);
	for (int i = 0; i < D; i++)
		cin >> pro[i].first >> pro[i].second;
	ll ans = 1e5;
	ll twos = pow(2, D);
	for (int i = 0; i < twos; i++) {
		ll temp = i, scr = 0, kari = 0;
		vector<int> bit(D);
		for (int j = 0; temp > 0; j++) {
			bit[j] = temp % 2;
			temp /= 2;
		}
		for (int j = 0; j < D; j++) {
			if (bit[j]==1) {
				scr += 100 * (j + 1) * pro[j].first + pro[j].second;
				kari += pro[j].first;
			}
			
		}
		if (scr < G) {
			for (int j = D - 1; j >= 0; j--) {
				if (bit[j]==0) {
					int rem = (G - scr + 100 * (j + 1) - 1) / (100 * (j + 1));
					//cout << "i=" << i << " ";
					//cout << "j=" << j << " rem=" << rem << " G-scr=" << G - scr << endl;
					if (rem < pro[j].first) kari += rem, scr += rem * 100*(j + 1);
					break;
				}
			}
		}
		//cout << "i=" << i;
		//cout << " scr=" << scr  ;
		//cout << " kari=" << kari << endl;
		if (scr >= G) {
			
			ans = min(ans, kari);
		}
	}
	cout << ans << endl;
}
