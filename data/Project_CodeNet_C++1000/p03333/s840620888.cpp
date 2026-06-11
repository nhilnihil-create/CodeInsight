#include <iostream>
#include <math.h>
#include <vector>
#include <stack>
#include <cstdio>
#include <string>
#include <bitset>
#include <list>
#include <set>
#include <algorithm>
#include <numeric>
#include <unordered_map>
#include <functional>
#include <queue>
// #include "bits/stdc++.h"

using namespace std;
//debug

#define rep(i, N) for (int i = 0; i < N; i++)
#define rep2(i, N, M) for (int i = N; i < M; i++)
#define pb push_back



typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef priority_queue<pll, vector<pll>, greater<pll>> greater_pq;


#define all(a)  (a).begin(),(a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define vec(a) vector<a>

int main() {
	ll N;
	cin >> N;
	vector<pll> L(N), R(N);
	rep(i, N) {
		cin >> L.at(i).first >> R.at(i).first;
		L.at(i).second = i;
		R.at(i).second = i;
	}

	sort(all(L));
	sort(all(R), greater<pll>());
	auto L_2 = L;
	auto R_2 = R;
	ll x = 0;
	ll res=0;
	//case r
	rep(i, N) {
		if (i % 2 == 0) {
			res += max(L.back().first - x, 0LL);
			x += max(L.back().first - x, 0LL);
			L.pop_back();
		}
		else {
			res += max(x-R.back().first , 0LL);
			x -= max(x-R.back().first, 0LL);
			R.pop_back();
		}
	}
	res += abs(x);
	//case l
	x = 0;
	ll res_2 = 0;
	L = L_2;
	R = R_2;
	rep(i, N) {
		if (i % 2 ==1) {
			res_2 += max(L.back().first - x, 0LL);
			x += max(L.back().first - x, 0LL);
			L.pop_back();
		}
		else {
			res_2 += max(x - R.back().first, 0LL);
			x -= max(x - R.back().first, 0LL);
			R.pop_back();
		}
	}
	res_2 += abs(x);
	
	cout << max(res, res_2)<<endl;
	return 0;
}

