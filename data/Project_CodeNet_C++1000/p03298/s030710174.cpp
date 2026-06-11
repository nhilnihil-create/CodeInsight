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
	int N;
	cin >> N;

	string L,R;
	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		L.push_back(a);
	}

	for (int i = 0; i < N; i++) {
		char a;
		cin >> a;
		R.push_back(a);
	}
	reverse(R.begin(), R.end());

	ll mx = pow(2, N);
	map<pair<string, string>, ll> Left, Right;
	for (ll i = 0; i < mx; i++) {
		//cout << "i=" << i << endl;
		vector<int> bit(N);
		ll temp = i;
		for (int j = 0; temp > 0; j++) {
			bit[j] = temp % 2;
			temp /= 2;
		}

		string red,blue;
		for (int k = 0; k < N; k++) {
			if (bit[k]) red.push_back(L[k]);
			else blue.push_back(L[k]);
		}
		Left[make_pair(red, blue)]++;

		string red2, blue2;
		for (int k = 0; k < N; k++) {
			if (bit[k]) red2.push_back(R[k]);
			else blue2.push_back(R[k]);
		}
		Right[make_pair(red2, blue2)]++;
	}

	ll ans = 0;
	int cnt = 1;
	/*
	for (auto y : Right) {
		cout << y.first.first << " " << y.first.second << " ";
		cout << y.second << endl;
	}
	*/
	for (auto x : Left) {
		//cout << "cnt=" << cnt << " ";
		//cout << x.first.first << " " << x.first.second << " ";
		//cout << x.second << endl;;
		//cout << Right[x.first] << " " << endl;
		ans += x.second * Right[x.first];
		cnt++;
	}

	cout << ans << endl;
}
