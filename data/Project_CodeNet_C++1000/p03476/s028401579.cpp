#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;


int main() {
	set<int>prime;
	vector<int>like(1e5, 0);
	bool isPrime = true;
	for (int i = 2; i <= 1e5; i++) {
		isPrime = true;
		for (int j = 2; (j * j) <= i; j++) {
			if (i % j == 0) {isPrime = false; break;}
		}
		if (isPrime)prime.insert(i);
		if (isPrime && prime.count((i + 1) / 2))like[i] = 1;
	}

	vector<int>likesum((1e5) + 1, 0);
	rep(i, 1e5) {
		likesum[i + 1] = likesum[i] + like[i];
	}

	int q;
	cin >> q;
	int l, r;
	rep(i, q) {
		cin >> l >> r;
		cout << likesum[r+1] - likesum[l] << endl;
	}

	return 0;
}

