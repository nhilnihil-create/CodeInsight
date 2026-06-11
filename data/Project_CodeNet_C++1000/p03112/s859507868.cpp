#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

//#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int A, B, Q;
	cin >> A >> B >> Q;

	vector<ll> s(A), t(B);
	for (int i = 0; i < A; i++)
		cin >> s[i];
	for (int i = 0; i < B; i++)
		cin >> t[i];

	//vector<ll> x(Q);
	for (int i = 0; i < Q; i++) {
		ll x;
		cin >> x;
		int sr = lower_bound(s.begin(), s.end(), x) - s.begin() ;
		int sl = sr - 1;
		int tr = lower_bound(t.begin(), t.end(), x) - t.begin() ;
		int tl = tr - 1;
		/*
		cout << "sr=" << sr << " ";
		cout << "sl=" << sl << " ";
		cout << "tr=" << tr << " ";
		cout << "tl=" << tl << " ";
		cout << endl;
		*/
		ll ans = 1e15;
		if (sl >= 0) {
			if (tl >= 0)
				ans = min(ans, max(abs(x-s[sl]), abs(x-t[tl])));
			if (tr < B)
				ans = min(ans, 2 * min(abs(x - s[sl]), abs(x - t[tr])) + max(abs(x - s[sl]), abs(x - t[tr])));
		}
		if (sr < A) {
			if (tr < B)
				ans = min(ans, max(abs(x - s[sr]), abs(x - t[tr])));
			if (tl >= 0)
				ans = min(ans, 2 * min(abs(x - s[sr]), abs(x - t[tl])) + max(abs(x - s[sr]), abs(x - t[tl])));
		}
		cout << ans << endl;
	}
}
